import math

n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    if y % x != 0:
        print(0)
        continue
    m = y // x
    summ = 0
    for j in range(1, m + 1):
        if m % j == 0:
            k = m // j
            if math.gcd(j, k) == 1:
                summ = summ + 1
    print(summ)
