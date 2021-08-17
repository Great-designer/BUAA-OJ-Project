lis = [[0 for i in range(150)]for i in range(150)]
d = int(input())
n = int(input())
s = []
for i in range(n):
    x,y,k = map(int,input().split())
    lis[x][y]=k

for i in range(129):
    for j in range(129):
        s.append(0)
        for ii in range(-1*d,d+1):
            s[-1] += sum(lis[i+ii][j-d:j+d+1])
s.sort(reverse=True)
print(s.count(s[0]),s[0])
