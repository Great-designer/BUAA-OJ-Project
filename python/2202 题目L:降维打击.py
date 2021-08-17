n, m = map(int,input().split())
l = 0
for i in range(n):
    a, b = map(int,input().split())
    if b == 1:
        l = max(l,m-a)
    else:
        l = max(a,l)
print(l)
