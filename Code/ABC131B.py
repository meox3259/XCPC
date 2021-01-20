n, L = map(int, input().split(' '))
sum = 0
for i in range(n):
    sum = sum + (i + L)
delta = 1000000000
for i in range(n):
    d = i + L
    if(abs(d) < abs(delta)):
        delta = d
print(sum - delta)

