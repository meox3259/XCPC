h, w = map(int, input().split(' '))
sx, sy = map(int, input().split(' '))
sx = sx - 1
sy = sy - 1

S = [[char] * w] * h
d = [[int] * w] * h

for i in range(h):
    for j in range(w):
        S[i][j] = input()

from collections import deque
dq = deque
dq.append((sx, sy, 0))

while dq:
    h, w, d = dq.popleft()
    if (0 <= h < H and 0 <= w < W and )
