def dis(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

T = int(input())

for _ in range(T):
    n, m, r, c = map(int, input().split())
    print(max(dis(1, 1, r, c), dis(1, m, r, c), dis(n, 1, r, c), dis(n, m, r, c)))
