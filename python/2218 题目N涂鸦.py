# 逆序涂色,涂满即停
n, m, k = map(int, input().split())
canvas = [[0 for i in range(m)] for j in range(n)]
step = []
num = 0
for i in range(k):
    step.append(list(map(int, input().split())))
for i in range(k - 1, -1, -1):
    if step[i][0] == 1:
        for j in range(m):
            if canvas[step[i][1] - 1][j] == 0:
                canvas[step[i][1] - 1][j] = step[i][2]
                num += 1
                if num == n * m:
                    break
        else:
            continue
        break
    else:
        for j in range(n):
            if canvas[j][step[i][1] - 1] == 0:
                canvas[j][step[i][1] - 1] = step[i][2]
                num += 1
                if num == n * m:
                    break
        else:
            continue
        break
for i in range(n):
    print(*canvas[i])
