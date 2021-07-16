Lalla = [""] * 10000
n = int(input())

space = (n - 1) >> 1
count = 1
i = 0
while space >= 0:
    Lalla[i] += " " * space
    Lalla[i] += "*" * count
    space -= 1
    count += 2
    i += 1
space = 1
count = n - 2
while i < n:
    Lalla[i] += " " * space
    Lalla[i] += "*" * count
    space += 1
    count -= 2
    i += 1
for i in range(n):
    print(Lalla[i])
