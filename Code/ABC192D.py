s = input()
x = int(input())
d = 0
for i in range(len(s)):
    d = max(d, int(s[i]))
l = d
r = 10**18 + 1
while (r - l > 1):
    mid = (l + r) // 2
    pw = 1
    Sum = 0
    for i in range(len(s) - 1, -1, -1):
        Sum += pw * int(s[i])
        pw = pw * mid
    if (Sum <= x):
        l = mid
    else:
        r = mid
if len(s) == 1:
    if int(s[0]) <= x:
        print(1)
    else:
        print(0)
else:
    print(l - d)

