r, d, x = map(int, input().split(' '))
for i in range(10):
    x = x * r - d
    print(x)
