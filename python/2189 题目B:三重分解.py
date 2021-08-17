n = int(input())
if n>=3:
    print('YES')
    if n % 3 == 0:
        print(1,1,n-2)
    elif n % 3 == 1:
        print(1,1,n-2)
    else:
        print(1,2,n-3)
else:
    print("impossible")
