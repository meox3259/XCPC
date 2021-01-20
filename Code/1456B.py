n = int(input())
a = list(map(int, input().split(' ')))
if (n > 60):
    print(1)
    exit(0)
pre = [None] * (n + 1)
pre[0] = 0
for i in range(n):
    pre[i + 1] = pre[i] ^ a[i]
ans = 1000000000
for i in range(1, n + 1):
    for j in range(i, n + 1):
        for k in range(j + 1, n + 1):
            if ((pre[i - 1] ^ pre[j]) > (pre[k] ^ pre[j])):
                ans = min(ans, k - i - 1)
if (ans == 1000000000):
    print(-1)
else:
    print(ans)

