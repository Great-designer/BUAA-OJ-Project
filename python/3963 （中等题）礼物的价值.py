T = int(input())

for i in range(T):
    n = int(input())
    name = []
    money = []
    for j in range(n):
        name.append(input())
        money.append(0)
    for j in range(n):
        ni = name.index(input())
        pm, m = map(int, input().split())
        if m == 0:
            continue
        money[ni] += -1 * m * (pm // m)
        for k in range(m):
            money[name.index(input())] += pm // m
    for j in range(n):
        print(name[j], money[j])
    print()
