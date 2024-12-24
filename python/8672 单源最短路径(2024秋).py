import heapq

def dijkstra(n, edges, start, end):
    graph = [[] for _ in range(n + 1)]
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))

    dist = [float('inf')] * (n + 1)
    dist[start] = 0
    prev = [-1] * (n + 1)
    pq = [(0, start)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                prev[v] = u
                heapq.heappush(pq, (dist[v], v))

    path = []
    u = end
    while u != -1:
        path.append(u)
        u = prev[u]
    path.reverse()

    return dist[end], path

def main():
    n, m, s, t = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))

    distance, path = dijkstra(n, edges, s, t)
    print(distance)
    print(' '.join(map(str, path)))

if __name__ == "__main__":
    main()
