a = int(input())
b = int(input())
n = int(input())
lis = [a, b]
for i in range(2,n):
    lis.append(lis[i-2]*lis[i-1])
print(lis[n-1])
