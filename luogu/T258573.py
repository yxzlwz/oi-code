t = int(input())


def okm(l):
    for i in range(10):
        if l.count(i) < 2:
            continue
        ll = l.copy()
        ll.remove(i)
        ll.remove(i)
        ll.sort()
        if ll[0] + 2 == ll[1] + 1 == ll[2]:
            return True
    return False


while t:
    t -= 1
    n = input().split(' ')
    n = [int(i) for i in n]
    for i in range(10):
        if okm(n + [i]):
            print(1)
            break
    else:
        print(0)
