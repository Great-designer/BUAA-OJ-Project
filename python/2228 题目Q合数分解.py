n = int(input())

if n % 4 == 1:  # 9=9
    m = n // 4 - 1
elif n % 4 == 3:
    m = n // 4 - 1  # 15=9+6
else:
    m = n // 4  # 6=6,4=4
if m < 1 or n == 11:
    m = -1
print(m)
