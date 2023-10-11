import sys
sys.setrecursionlimit(10**6 + 10)

N = int(input())
g = [[] for i in range(N)]
path = True
for i in range(N-1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
    if (len(g[a]) > 2 or len(g[b]) > 2):
        path = False

def dfs(u, par = -1):
    result = 1
    count = 0
    for v in g[u]:
        if (v != par):
            dpV = dfs(v, u)
            if (dpV > result):
                result = dpV
                count = 1
            elif (dpV == result):
                count += 1

    if (count > 1):
        result += 1

    return result

if (path):
    print(1)
else:
    print(dfs(0))
