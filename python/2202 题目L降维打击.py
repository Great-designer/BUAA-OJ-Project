n, m = map(int, input().split())
ll = 0
for i in range(n):
    a, b = map(int, input().split())
    if b == 1:
        ll = max(ll, m - a)
    else:
        ll = max(a, ll)
print(ll)
