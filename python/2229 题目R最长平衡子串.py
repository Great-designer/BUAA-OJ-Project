n = int(input())
lis = list(input().split())
d = [0]
max_i = 0
m = {}
for i in range(n):
    if lis[i] == "1":
        d.append(d[-1] + 1)
    else:
        d.append(d[-1] - 1)
for i in range(len(d)):
    if d[i] in m:
        m[d[i]].append(i)
    else:
        m[d[i]] = [i]
for i in m:
    if len(m[i]) > 1:
        max_i = max(m[i][-1] - m[i][0], max_i)
print(max_i)
