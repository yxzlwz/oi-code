a = input().lower()
b = input().lower()

m = b.count(a)
n = -1
try:
    n = b.index("%s " % a)
except:
    try:
        n = b.index(" %s" % a)
    except:
        ...
if n == -1:
    print(-1)
else:
    print("%d %d" % (m, n))
