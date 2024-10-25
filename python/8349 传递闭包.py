def warshall_algorithm(n, edges):
    # 初始化邻接矩阵
    graph = [[False] * n for _ in range(n)]
    
    # 填充邻接矩阵
    for u, v in edges:
        graph[u-1][v-1] = True
    
    # Warshall 算法计算传递闭包
    for k in range(n):
        for i in range(n):
            for j in range(n):
                graph[i][j] = graph[i][j] or (graph[i][k] and graph[k][j])
    
    # 收集结果
    result = []
    for i in range(n):
        for j in range(n):
            if graph[i][j]:
                result.append((i+1, j+1))
    
    return result

# 读取输入
n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

# 计算传递闭包
result = warshall_algorithm(n, edges)

# 输出结果
for u, v in sorted(result):
    print(u, v)