k, l, r, t, x, y = map(int, input().split(' '))

if (x >= y):
    if (k + y > r):
        bad = False
        k -= x
        if (k < l):
            bad = True
        t -= 1
        if (k - t * (x - y) < l):
            bad = True
        if (bad):
            print("No")
        else:
            print("Yes")
    else:
        if (k - t * (x - y) < l):
            print("No")
        else:
            print("Yes")
else:
    days = 0;
    d = (k - l) // x
    days += d
    k -= d * x
    vis = [False] * (x + 1)
    bad = False
    while (True):
        if (days >= t):
            break
        if (vis[(k - l) % x]):
            break
        vis[(k - l) % x] = True
        k += y
        if (k > r):
            bad = True
        dd = (k - l) // x
        days += dd;
        k -= dd * x
    bad = False
    for i in range(0, x):
        if (vis[i] == True and l + i + y > r):
            bad = True
    if (bad):
        print("No")
    else:
        print("Yes")
