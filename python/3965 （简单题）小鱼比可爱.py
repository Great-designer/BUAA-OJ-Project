n = int(input())
lis = list(map(int, input().split()))
ll = []
for i in range(n):
    summ = 0
    for j in range(i):
        if lis[j] < lis[i]:
            summ += 1
    ll.append(summ)
print(*ll)
