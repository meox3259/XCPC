s = input()
a = int(s[0:2])
b = int(s[2:4])
if (1 <= a and a <= 12):
    if (1 <= b and b <= 12):
        print("AMBIGUOUS")
    else:
        print("MMYY")
elif (1 <= b and b <= 12):
    print("YYMM")
else:
    print("NA")
