n, m = map(int, input().split())
m = m + 1
ai = list(map(int, input().split()))
mini = 0
maxi = max(ai)
while maxi - mini > 1e-4:
    mid = (maxi + mini) / 2
    s = 0
    for i in range(n):
        s = s + (ai[i] // mid)
    if s >= m:
        mini = mid
    else:
        maxi = mid
print(mid)
