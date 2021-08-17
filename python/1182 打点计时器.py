x = []
v = []
t = 0
for i in range(6):
    x.append(float(input()))
for i in range(4):
    v.append((x[i+2]-x[i])*0.1)
    t += (x[i+2]-x[i])*0.1
t = t/4
a = ((v[0]-t)*(-0.075)+(v[1]-t)*(-0.025)+(v[2]-t)*(0.025)+(v[3]-t)*(0.075))/(2*(0.075**2)+2*(0.025**2))
print("%.3f"%a)
print("%.5f"%(abs(a-9.8)/9.8))
