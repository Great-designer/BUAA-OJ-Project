myapp = [[0] for _ in range(210)]
myapp[1] = 1
myapp[2] = 2
for i in range(3, 210):
    myapp[i] = myapp[i - 1] + myapp[i - 2]

n = int(input())
print(myapp[n])
