# 有很大优化余地
n = int(input())
d = int(input())
l2 = [([0] * d) for i in range(d)]
i = 0
j = 1
x = 0
y = 0
while i < 2 * d - 1:
    if i % 4 == 0:
        while y < d:
            if l2[x][y] != 0:
                break
            l2[x][y] = j
            j = j + 1
            y = y + 1
            if j > n:
                j = 1
        y = y - 1  # 换方向
        x = x + 1
    if i % 4 == 1:
        while x < d:
            if l2[x][y] != 0:
                break
            l2[x][y] = j
            j = j + 1
            x = x + 1
            if j > n:
                j = 1
        x = x - 1
        y = y - 1
    if i % 4 == 2:
        while 0 <= y < d:
            if l2[x][y] != 0:
                break
            l2[x][y] = j
            j = j + 1
            y = y - 1
            if j > n:
                j = 1
        y = y + 1
        x = x - 1
    if i % 4 == 3:
        while 0 <= x < d:
            if l2[x][y] != 0:
                break
            l2[x][y] = j
            j = j + 1
            x = x - 1
            if j > n:
                j = 1
        x = x + 1
        y = y + 1
    i = i + 1
for x in range(d):
    for y in range(d):
        print(l2[x][y], end=' ')
    print()
