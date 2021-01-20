a, b, c = map(int, input().split(' '))

P = 998244353

def f(x):
    return x * (x + 1) // 2 % P

print(f(a) * f(b) % P * f(c) % P)
