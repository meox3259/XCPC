k, x = map(int, input().split(' '))
for i in range(x - k, x + k - 1):
    print(i + 1, end = ' ')
