N, Q, H = map(int, input().split())

# Implementation of DSU
e = [-1 for i in range(N)]
def find(u): 
    if (e[u] < 0):
        return u
    e[u] = find(e[u])
    return e[u]
def unite(a, b):
    a, b = find(a), find(b)
    if (a == b): return 
    if (e[a] > e[b]): a, b = b, a
    e[a] += e[b]
    e[b] = a

# Input platforms and add endpoints to list of events, aswell as keeping track of possible y-values.
events = []
bigY = set()
for i in range(N):
    x, y, l = map(int, input().split())
    events.append((x, 1, y, i))
    events.append((x + l, -1, y, i))
    bigY.add(y)
events.sort()

# Coordinate Compression
bigY = sorted(list(bigY))
M = len(bigY)
smolY = {}
for i in range(M):
    smolY[bigY[i]] = i

#Implementation of segment tree.

segL = [None for i in range(4 * M)]
segR = [None for i in range(4 * M)]
def update(v, tl, tr, idx, val):
    if (tl == tr):
        segL[v] = val
        segR[v] = val
        return

    tm = (tl + tr) // 2
    if (idx <= tm):
        update(2 * v, tl, tm, idx, val)
    else:
        update(2 * v + 1, tm + 1, tr, idx, val)

    segL[v] = segL[2 * v] if segL[2 * v] is not None else segL[2 * v + 1]
    segR[v] = segR[2 * v + 1] if segR[2 * v + 1] is not None else segR[2 * v]

def queryL(v, tl, tr, l, r):
    if (tr < l or r < tl):
        return None
    if (l <= tl and tr <= r):
        return segL[v]
    tm = (tl + tr) // 2
    ansL = queryL(2 * v, tl, tm, l, r)
    if (ansL is not None):
        return ansL
    return queryL(2 * v + 1, tm + 1, tr, l, r)

def queryR(v, tl, tr, l, r):
    if (tr < l or r < tl):
        return None
    if (l <= tl and tr <= r):
        return segR[v]
    tm = (tl + tr) // 2
    ansR = queryR(2 * v + 1, tm + 1, tr, l, r)
    if (ansR is not None):
        return ansR
    return queryR(2 * v, tl, tm, l, r)

# Loop through events and find adjacent platforms with segment tree when processing new platforms.
for x, t, y, i in events:
    if (t == 1):
        res = queryR(1, 0, M - 1, 0, smolY[y] - 1)
        if (res is not None):
            if (abs(res[1] - y) <= H):
                unite(i, res[0])
        res = queryL(1, 0, M - 1, smolY[y] + 1, M - 1)
        if (res is not None):
            if (abs(res[1] - y) <= H):
                unite(i, res[0])
        update(1, 0, M - 1, smolY[y], (i, y))
    else:
        update(1, 0, M - 1, smolY[y], None)

# Get input queries and use DSU to process them.
for _ in range(Q):
    a, b = map(int, input().split()); a -= 1; b -= 1
    print("YES" if find(a) == find(b) else "NO")
