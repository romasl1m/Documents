import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    tab: list[tuple[int, int]] = []
    for _ in range(n):
        a, b = map(int, input().split())
        tab.append((a, b))
    l = 0
    r = n + 1
    while l < r - 1:
        mid = l + (r - l) // 2
        cur = 0
        for a, b in tab:
            if mid - a - 1 <= cur <= b:
                cur += 1
        if cur >= mid:
            l = mid
        else:
            r = mid
    print(l)
