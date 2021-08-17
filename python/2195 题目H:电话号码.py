n = int(input())
num = list(map(int,input().split()))
if(num[0:n-7].count(8)>(n-8)/2):
    print("YES")
else:
    print("NO")
