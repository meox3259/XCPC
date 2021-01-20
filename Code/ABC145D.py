def power(x, y, P):
    ret = 1
    while (y != 0):
        if (y & 1):
           ret = ret * x % P
        x = x * x % P
        y >>= 1
    return ret;

x, y = map(int, input().split(' '))
P = 10**9 + 7
ans = 0
fac = [None] * (x + y + 1)
fac[0] = 1
for i in range(1, x + y + 1):
    fac[i] = fac[i - 1] * i % P
for i in range(0, x + 1):
    if (x - i) % 2 == 0:
        j = (x - i) // 2
        if i + i + j == y:
            ans = (ans + fac[i + j] * power(fac[i], P - 2, P) % P * power(fac[j], P - 2, P) % P) % P
print(ans)
