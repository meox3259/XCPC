import itertools
from itertools import permutations
n = int(input())
l = [list(map(int, input().split(' '))) for i in range(n)]
p = list(permutations(range(n)))
ans = 0
for i in range(len(p)):
    for j in range(n - 1):
        x1, y1 = l[p[i][j]]
        x2, y2 = l[p[i][j + 1]]
        ans += ((x2 - x1)**2 + (y2 - y1)**2)**0.5
print(ans  / len(p))
