a = input().split(" ")
b = int(a[1])
a = int(a[0])
sum = {0:0, 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0, 9:0}
for i in range(a, b+1):
    t = str(i)
    for j in range(10):
        sum[j] += t.count(str(j))
for i, j in sum.items():
    print(str(j) + " ", end="")
