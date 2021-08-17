def f(n):
    if n <= 1:
        return n
    else:
        return f(n - 1) + f(n - 2)


t = int(input())
for i in range(t):
    nn = int(input())
    lis = []
    for j in range(nn + 2):
        a = f(j)
        if a > nn:
            break
        lis.append(a)
    print(*lis)
