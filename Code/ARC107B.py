n, k = map(int, input().split(' '))
k = abs(k)
ans = 0
def f(x):
    low = max(1, x - n)
    high = min(n, x - 1)
    return max(high - low + 1, 0)
for i in range(k + 2, k + n + n + 1):
    ans += f(i) * f(i - k)
print(ans)
