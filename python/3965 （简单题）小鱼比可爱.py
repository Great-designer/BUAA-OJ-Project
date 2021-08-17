n = int(input())
lis = list(map(int,input().split()))
l = []
for i in range(n):
    sum = 0
    for j in range(i):
        if lis[j]<lis[i]:
            sum+=1
    l.append(sum)
print(*l)
