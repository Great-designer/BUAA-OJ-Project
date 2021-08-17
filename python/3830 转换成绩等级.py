n = int(input())
for i in range(n):
    s = float(input())
    if 90 <= s <= 100:
        print("A")
    elif 80 <= s < 90:
        print("B")
    elif 70 <= s < 80:
        print("C")
    elif 60 <= s < 70:
        print("D")
    else:
        print("F")
