n = int(input())
a = []
for i in range(n):
    s, p = input().split(' ')
    a.append((s, int(p), i + 1))
a = sorted(a, key = lambda x : (x[0], -x[1]))
for i in range(n):
    print(a[i][2])
