a = int(input())
s = input()
for i in range(a):
    t = input()
    if t[0] == "1":
        s = s + t[2:]
    elif t[0] == "2":
        s = s[int(t[2]): int(t[2])+int(t[4])]
    elif t[0] == "3":
        s = s[:int(t[2])] + t[4:] + s[int(t[2]):]
    elif t[0] == "4":
        try:
            print(s.index(t[2:]))
            continue
        except:
            print(-1)
            continue
    print(s)
