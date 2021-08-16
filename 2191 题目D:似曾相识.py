n, m=map(int,input().split())
lis=[]
for i in range(n):
    a=input()
    if a in lis:
        print("NO")
    else:
        print("YES")
    lis.append(a)
