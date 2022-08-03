a = input()
if "." in a:
    a = a.split(".")
    a[0] = a[0][::-1]
    while a[0][0] == "0":
        a[0] = a[0][1:]
    a[1] = a[1][::-1]
    while a[1][0] == "0":
        a[1] = a[1][1:]
    print("%s.%s" % (a[0], a[1]))
elif "/" in a:
    a = a.split("/")
    a[0] = a[0][::-1]
    while a[0][0] == "0":
        a[0] = a[0][1:]
    a[1] = a[1][::-1]
    while a[1][0] == "0":
        a[1] = a[1][1:]
    print("%s/%s" % (a[0], a[1]))
elif "%" in a:
    a = a[:-1][::-1]
    while a[0] == "0":
        a = a[1:]
    print(a + "%")
else:
    print(a[::-1])