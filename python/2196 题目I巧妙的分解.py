n = int(input())
if n >= 3:
    print("YES")
    lis = [i for i in range(1, n + 1)]
    if n % 2 == 0:
        print("1", 2)
        print(n - 1, 1, *lis[2:])
    else:
        lis.remove((n + 1) // 2)
        print("1", (n + 1) // 2)
        print(n - 1, *lis)
else:
    print("impossible!")
