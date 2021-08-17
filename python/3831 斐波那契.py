def f(n):
    if n <= 1:
       return n
    else:
       return (f(n-1) + f(n-2))

t = int(input())
for i in range(t):
    n = int(input())
    lis = []
    for j in range(n+2):
        a = f(j)
        if a > n :
            break
        lis.append(a)
    print(*lis)
