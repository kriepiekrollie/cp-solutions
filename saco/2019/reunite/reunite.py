from queue import Queue
import math

N, M, A, B = map(int,input().split())

g = [[] for i in range(N + 1)]
for i in range(M):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)


def bfs(src):
    q = Queue()
    dist = [math.inf for i in range(N+1)]

    q.put(src)
    dist[src] = 0

    while not q.empty():
        u = q.get()
        for v in g[u]:
            if (dist[v] == math.inf):
                dist[v] = dist[u] + 1
                q.put(v)

    return dist

distA = bfs(A)
distB = bfs(B)

ans = 0
min_dist = math.inf
for i in range(N, 0, -1):
    distance = max(distA[i], distB[i])
    if min_dist >= distance:
        min_dist = distance
        ans = i

print(ans)
