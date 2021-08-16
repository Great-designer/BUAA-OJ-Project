T = int(input())

for i in range(T):
    n = int(input())
    lis = list(map(int,input().split()))
    l = 0
    sum = 0
    for j in range(n-1):
        if lis[j]>lis[j+1]:
            sum = 1
            while j+sum<n-1:
                if sum % 2 ==1:
                    if lis[j+sum]<lis[j+sum+1]:
                        sum +=1
                    else:
                        break
                else:
                    if lis[j+sum]>lis[j+sum+1]:
                        sum +=1
                    else:
                        break
        l = max(l,sum)
    print(l+1)
