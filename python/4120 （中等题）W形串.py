T = int(input())

for i in range(T):
    n = int(input())
    lis = list(map(int, input().split()))
    ll = 0
    summ = 0
    for j in range(n - 1):
        if lis[j] > lis[j + 1]:
            summ = 1
            while j + summ < n - 1:
                if summ % 2 == 1:
                    if lis[j + summ] < lis[j + summ + 1]:
                        summ += 1
                    else:
                        break
                else:
                    if lis[j + summ] > lis[j + summ + 1]:
                        summ += 1
                    else:
                        break
        ll = max(ll, summ)
    print(ll + 1)
