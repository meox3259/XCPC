n = int(input())

ok = 0
for i in range(1, 10):
    for j in range(1, 10):
        if i * j == n:
            ok = 1
print("Yes" if ok else "No")
