s = input()
t = input()

ans = 0
for i in range(3):
    ans += s[i] == t[i]
print(ans)
