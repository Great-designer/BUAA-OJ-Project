n = int(input())
aodd = 0
aeven = 0
bodd = 0
beven = 0
a = list(map(int,input().split()))
b = list(map(int,input().split()))
for i in range(n):
    if a[i]%2==0:
        aeven+=1
    else:
        aodd+=1
    if b[i]%2==0:
        beven+=1
    else:
        bodd+=1
print(min(aodd,beven)+min(aeven,bodd))
