T = int(input())
for i in range(T):
    a, b = map(int, input().split(' '))
    print((abs(a - b) + 9) // 10)
