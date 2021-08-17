n = int(input())
s = 791780
for i in range(70001, n + 1):
    for j in range(1, int(i ** 0.5) + 1):
        if i % j == 0:
            s += 2
    if j ** 2 == i:
        s -= 1
print(s)
