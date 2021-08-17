a, b, c = map(float,input().split())
d = (a+b+c)/3
print("%.2f %.2f"%(d ,(((a-d)**2+(b-d)**2+(c-d)**2)/2)**0.5))
