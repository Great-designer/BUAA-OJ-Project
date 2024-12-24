from collections import defaultdict, deque

def topological_sort(n, graph):
    in_degree = [0] * (n + 1)
    for u in range(1, n + 1):
        for v, _ in graph[u]:
            in_degree[v] += 1

    queue = deque([u for u in range(1, n + 1) if in_degree[u] == 0])
    topo_order = []

    while queue:
        u = queue.popleft()
        topo_order.append(u)
        for v, _ in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)

    return topo_order

def critical_path(n, m, s, t, edges):
    graph = defaultdict(list)
    for u, v, w in edges:
        graph[u].append((v, w))

    topo_order = topological_sort(n, graph)

    te = [-float('inf')] * (n + 1)
    te[s] = 0

    for u in topo_order:
        for v, w in graph[u]:
            if te[u] + w > te[v]:
                te[v] = te[u] + w

    tl = [float('inf')] * (n + 1)
    tl[t] = te[t]

    for u in reversed(topo_order):
        for v, w in graph[u]:
            if tl[v] - w < tl[u]:
                tl[u] = tl[v] - w

    buffer_time = [0] * (n + 1)
    for i in range(1, n + 1):
        if tl[i] == float('inf'):
            tl[i] = te[i]
        buffer_time[i] = tl[i] - te[i]

    critical_paths = []
    def dfs(u, path):
        if u == t:
            critical_paths.append(path[:])
            return
        for v, w in graph[u]:
            if te[u] + w == te[v]:
                path.append(v)
                dfs(v, path)
                path.pop()

    dfs(s, [s])
    critical_paths.sort(key=lambda x: (len(x), x))

    return te, tl, buffer_time, critical_paths

def main():
    n, m, s, t = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(m)]

    te, tl, buffer_time, critical_paths = critical_path(n, m, s, t, edges)

    print(te[t])
    for i in range(1, n + 1):
        te_str = 'inf' if te[i] == -float('inf') else str(te[i])
        tl_str = 'inf' if tl[i] == float('inf') else str(tl[i])
        buffer_str = 'inf' if buffer_time[i] == float('inf') else str(buffer_time[i])
        print(te_str, tl_str, buffer_str)

    for path in critical_paths:
        print(' '.join(map(str, path)))

if __name__ == "__main__":
    main()
