n = int(input())
r = int(input())
while True:
    print(n%r)
    n = n // r
    if n == 0:
        break
