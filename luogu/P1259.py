#pythran export work(int )
def work(n):
    a = []
    S = """ooo--***o*
    ooo*o**--*
    o--*o**oo*
    o*o*o*--o*
    --o*o*o*o*""".split('\n')
    ans = []

    for i in range(n):
        a.append('o')
    for i in range(n):
        a.append('*')
    a.append('-')
    a.append('-')

    # print(''.join(a))
    ans.append(''.join(a))

    while ''.join(a)[:8] != 'oooo****':
        s = ''.join(a)
        i = s.index('o*')
        j = s.index('--')
        a[i] = a[i + 1] = '-'
        a[j] = 'o'
        a[j + 1] = '*'
        # print(''.join(a))
        ans.append(''.join(a))
        a[i] = a[j - 2]
        a[i + 1] = a[j - 1]
        a[j - 2] = a[j - 1] = '-'
        # print(''.join(a))
        ans.append(''.join(a))

    for j in S:
        # print(j + 'o*' * (n - 4))
        ans.append(j + 'o*' * (n - 4))


# print(a)
