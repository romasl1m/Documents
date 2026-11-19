# import sys
# sys.setrecursionlimit(100000)
n = int(input())

# tab = [0] * 100001
siz = [0] * (n + 1)
dist = [0] * (n + 1)
wec = [[] for _ in range(n + 1)]
tab = [0] + list(map(int, input().split()))

def dfs(w,p):
    stack
    siz[w] = 1
    for ss,cost in wec[w]:
        if ss == p:
            continue
        dist[ss] = max(0,dist[w] + cost,cost)
        dfs(ss,w)
        siz[w] += siz[ss]
res = 0
def check(w,p):
    global res 
    if dist[w] > tab[w]:
        res += siz[w]
    else:
        for ss,cost in wec[w]:
            if ss == p:
                continue
            check(ss,w)


# for i in range(1,n + 1):
#     tab[i] = 
# tab = list(map(int,input()))
for i in range(2,n + 1):
    # p,c = map(int,input()) 
    p, c = map(int, input().split())
    wec[i].append((p, c))
    wec[p].append((i, c))

dfs(1,0)
check(1,0)
print(res)

