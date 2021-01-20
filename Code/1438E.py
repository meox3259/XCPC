n = int(input())
a = list(map(int, input().split(' ')))
ans = 0
for i in range(n):
    sum = 0
    for j in range(i + 2, n, 1):
        sum += a[j - 1]
        if (sum >= a[i] + a[i]):
            break
        if ((a[i] ^ a[j]) == sum and a[i] >= a[j]):
            ans += 1
for i in range(n):
    sum = 0
    for j in range(i - 2, -1, -1):
        sum += a[j + 1]
        if (sum >= a[i] + a[i]):
            break
        if ((a[i] ^ a[j]) == sum and a[i] > a[j]):
            ans += 1
print(ans)
