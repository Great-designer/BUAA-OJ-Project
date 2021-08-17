n = int(input())
lis = list(map(int, input().split()))
diff = []
for i in range(n - 1):
    diff.append(lis[i + 1] - lis[i])
print(lis[0], min(diff))
