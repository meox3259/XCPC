n = int(input())
w = list(map(int, input().split(' ')))
pre = range(n + 1)
pre[0] = 0
for i in range(n):
    pre[i + 1] = pre[i] + w[i]
ans = pre[n]
for i in range(1, n):
    ans = min(ans, abs(pre[n] - pre[i] - pre[i]))
print(ans)

