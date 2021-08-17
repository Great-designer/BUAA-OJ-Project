m, b, h = map(int,input().split())
h = b + h
sum = 0
for i in range(m):
    o = int(input())
    if o<=h:
        sum+=1
print(sum) 
