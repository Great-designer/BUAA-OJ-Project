m, b, h = map(int, input().split())
h = b + h
summ = 0
for i in range(m):
    o = int(input())
    if o <= h:
        summ += 1
print(summ)
