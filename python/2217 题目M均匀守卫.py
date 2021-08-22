n, m = map(int, input().split())
lis = [i * (n + m) / n for i in range(n)]
change = 0
for i in range(n):
    change += min((lis[i] - int(lis[i])), (int(lis[i]) + 1 - lis[i]))
print(change)
