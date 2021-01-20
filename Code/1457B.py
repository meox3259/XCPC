T = int(input())

for _ in range(T):
    n, k = int(input().split())
    ans = n
    for i in range(101):
        j = 0
        t = 0
        while j < n:
            if c[j] != i:
                t += 1
                j += k
            else:
                j += 1
        ans = min(ans, t)
    print(ans)
