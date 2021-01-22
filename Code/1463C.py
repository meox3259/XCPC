def inside(a, b, x):
    if a > b:
        a, b = b, a
    if a <= x <= b:
        return True
    else:
        return False

T = int(input())
for _ in range(T):
    n = int(input())
    ans = 0
    move = False
    pre = 0
    last = 0
    sgn = 1
    to = 0
    pos = 0
    for i in range(n):
        t, x = map(int, input().split(' '))
        diff = t - pre
        if move and to != pos:
            sgn = (to - pos) / abs(to - pos)
        if abs(to - pos) <= diff:
            cur = to
            move = False
        else:
            cur = pos + sgn * diff
        if inside(cur, pos, last):
            ans += 1
        if not move:
            move = True
            to = x
        pos = cur
        pre = t;
        last = x
    if inside(to, pos, last):
        ans += 1
    print(ans - 1)

