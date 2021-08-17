t = int(input())

for i in range(t):
    n = int(input())
    lis = []
    for j in range(2, n + 1):
        summ = 1
        for k in range(2, j):
            if j % k == 0:
                summ = summ + k
        if summ == j:
            lis.append(j)
    print(*lis)
