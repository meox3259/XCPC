def s(n):
    return sum([int(a) for a in str(n)])
def c(n):
    return n / s(n)

k = int(input())
n = 0
d = 1
while (k > 0):
    t1 = c(n + d)
    t2 = c(n + 10 * d)
    if (t1 > t2):
        d = d * 10
    n += d
    print(n)
    k -= 1


