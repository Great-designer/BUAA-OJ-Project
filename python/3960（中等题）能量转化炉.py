T = int(input())

for i in range(T):
    n = int(input())
    sum = 0.0
    lis = list(map(int,input().split()))
    lis.sort()
    for j in range(n-1):
        sum+=lis[j]
    if sum >= lis[-1]:
        print("%.1f"%((sum+lis[-1])/2))
    else:
        print("%.1f"%sum)
