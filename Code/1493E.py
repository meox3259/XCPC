n = int(input())
l = input()
r = input()
if l == r:
    print(r)
elif l[0] != r[0]:
    print('1' * n)
elif r[-1] == '1' or int(l, 2) + 1 == int(r, 2):
    print(r)
else:
    print(r[:-1] + '1')
