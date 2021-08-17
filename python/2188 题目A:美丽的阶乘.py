n = int(input())
a = 0
b = 1
while n//(5**b):
    a+=n//(5**b)
    b+=1
print(a)
