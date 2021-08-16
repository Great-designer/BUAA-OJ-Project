n = int(input())
lis = [0,0,0]
state = True
for i in range(n):
    a, b = map(int,input().split())
    c = b-a*5
    if c == 15:
        if lis[1]>=1 and lis[0]>=1:
            lis[1]-=1
            lis[0]-=1
        elif lis[0]>=3:
            lis[0]-=3
        else:
            state = False
            break
    if c == 10:
        if lis[1]>=1 :
            lis[1]-=1
        elif lis[0]>=2:
            lis[0]-=2
        else:
            state = False
            break
    if c == 5:
        if lis[0]>=1:
            lis[0]-=1
        else:
            state = False
            break
    if b == 20:
        lis[2]+=1
    elif b == 10:
        lis[1]+=1
    elif b == 5:
        lis[0]+=1

print(state)
