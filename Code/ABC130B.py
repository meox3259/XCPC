n, x = map(int, input().split(' '))
L = list(map(int, input().split(' ')))
ans = 1
d = 0
for i in L:
    d += i
    if d <= x:
        ans += 1
print(ans)

