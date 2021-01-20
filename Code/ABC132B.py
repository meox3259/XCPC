n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in range(1, n - 1):
    if min(a[i - 1], a[i], a[i + 1]) != a[i] and max(a[i - 1], a[i], a[i + 1]) != a[i]:
        ans += 1
print(ans)

