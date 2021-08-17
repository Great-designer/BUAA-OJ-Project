x, y = map(float, input().split())
a, b, c = map(float, input().split())
print("%.3f" % (abs(a * x + b * y + c) / ((a ** 2 + b ** 2) ** 0.5)))
