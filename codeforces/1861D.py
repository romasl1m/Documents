# Now playing:
# YFN Lucci - EXPOSED. ft Quavo. [EXPOSED. ft Quavo.]
# import sys
# input = sys.stdin.read
t = int(input())
for _ in range(t):
    n = int(input())
    tab = list(map(int,input().split()))

    res = n
    lstgr = 0
    for i in range(n - 1):
        if tab[i] >= tab[i + 1]:
            lstgr += 1
    lstsm = 0

    for i in range(0,n + 1):
        cur = lstgr + lstsm
        if i > 0:
            cur += 1
        res = min(res,cur)
        if i < n - 1 and tab[i] >= tab[i + 1]:
            lstgr -= 1
        if 0 < i < n and tab[i] >= tab[i - 1]:
            lstsm += 1
    print(res)
