n = int(input())
lis = [[0 for i in range(n + 1)] for j in range(n + 1)]

for i in range(1, n + 1):
    lis[1][i] = 2 - (i % 2)
    lis[i][1] = 2 - (i % 2)
for i in range(2, n + 1):
    for j in range(i, n + 1):  # 对称阵
        lis[i][j] = lis[i - 1][j] + lis[i][j - 1]
        lis[j][i] = lis[i][j]
print(lis[n][n])
