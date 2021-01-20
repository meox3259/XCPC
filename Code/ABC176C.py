n = int(input())
a = list(map(int, input().split(' ')))
Max = 0
ans = 0
for i in range(n):
    ans += max(0, Max - a[i])
    Max = max(Max, a[i])
print(ans)
