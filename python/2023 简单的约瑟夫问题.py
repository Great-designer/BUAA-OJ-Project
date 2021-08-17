n = int(input())
m = int(input())
a = 0
lis = [i for i in range(n)]
for i in range(n-1):
    a+=(m-1)
    a = a%len(lis)
    lis.pop(a)

print(lis[0]+1)
