T = int(input())
for kase in range(T):
    n = int(input())
    l = list(map(int, input().split(' ')))
    cur = 0
    for i in range(n - 1):
        dif = l[i + 1] - l[i]
        l[i] -= cur
        if (dif > 0):
            cur += dif
    l[n - 1] -= dif

    if (min(l) >= 0):
        print("YES")
    else:
        print("NO")
