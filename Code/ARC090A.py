n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
for i in range(n):
    sum = 0
    for j in range(n):
        if j <= i:
            sum += a[j]
        if j >= i:
            sum += b[j]
    ans = max(ans, sum)
print(ans)
