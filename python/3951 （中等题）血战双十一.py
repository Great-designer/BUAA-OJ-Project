T = int(input())

for i in range(T):
    a = 1
    n, m = map(int,input().split())
    lis = []
    for j in range(n):
        name,num = input().split()
        lis.append(name)
        lis.append(int(num))
    for k in range(m):
        good = input()
        if lis[lis.index(good)+1] > 0:
            lis[lis.index(good)+1] -= 1
        else:
            a = 0
    if a:
        for k in range(n):
            print(lis[2*k+1])
        print()
    else:
        print("Out of stock!")
        print()
