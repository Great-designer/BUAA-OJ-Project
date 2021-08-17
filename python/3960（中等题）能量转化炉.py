T = int(input())

for i in range(T):
    n = int(input())
    summ = 0.0
    lis = list(map(int, input().split()))
    lis.sort()
    for j in range(n - 1):
        summ += lis[j]
    if summ >= lis[-1]:
        print("%.1f" % ((summ + lis[-1]) / 2))
    else:
        print("%.1f" % summ)
