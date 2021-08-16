bud = int(input())
n = int(input())
s = 0
for i in range(n):
    p = float(input())
    if p >= 200:
        p1 = p-40
    elif p >= 100:
        p1 = p - 15
    elif p >= 50:
        p1 = p -5
    else:
        p1 = p
    s+=p1
if s>=1000:
    s = int(0.8*s)
elif s>=500:
    s = int(0.9*s)
else:
    s = int(s)
    
print(s)
if bud-s<0:
    print("chitu!")
else:
    print("enough!") 
