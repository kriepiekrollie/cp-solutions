n = int(input())
x = [0 for i in range(n-2)]
y = [0 for i in range(n-2)]
z = [0 for i in range(n-2)]
c = [0 for i in range(n-2)]
tri = {}

for i in range(n-2):
    x[i], y[i], z[i], c[i] = map(lambda x:int(x)-1, input().split())
    x[i], y[i], z[i] = sorted([x[i], y[i], z[i]])
    tri[(x[i], y[i])] = []
    tri[(x[i], z[i])] = []
    tri[(y[i], z[i])] = []

for i in range(n-2):
    tri[(x[i], y[i])].append(i)
    tri[(x[i], z[i])].append(i)
    tri[(y[i], z[i])].append(i)

g = [[] for i in range(n-2)]
for key in tri:
    if (len(tri[key]) != 2):
        continue
    g[tri[key][0]].append(tri[key][1])
    g[tri[key][1]].append(tri[key][0])

vis = [False for i in range(n-2)]
dp = [[0, 1] for i in range(n-2)]

def dfs(u, p = -1):
    vis[u] = True
    for v in g[u]:
        if (v != p and c[v] == c[u]):
            dfs(v, u)
            dp[u][1] += dp[v][0]
            dp[u][0] += max(dp[v][0], dp[v][1])

cnt = [0 for i in range(n-2)]
ans = 0
for i in range(n-2):
    if (not vis[i]):
        dfs(i)
        cnt[c[i]] += max(dp[i][0], dp[i][1])
        ans = max(ans, cnt[c[i]])
print(ans)

