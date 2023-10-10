W, H, w, h = map(int, input().split())

n = int(input())
Posters = []

xvaluess, yvaluess = {0, w, W - w, W}, {0, h, H - h, H}
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    Posters.append((x1, y1, x2, y2))

    xvaluess.add(max(0, x1 - w))
    xvaluess.add(x1)
    xvaluess.add(x2)
    xvaluess.add(min(W, x2 + w))

    yvaluess.add(max(0, y1 - h))
    yvaluess.add(y1)
    yvaluess.add(y2)
    yvaluess.add(min(H, y2 + h))

xvalues = sorted(list(xvaluess))
yvalues = sorted(list(yvaluess))

compressed_X = {}
countX = 0
for x in xvalues:
    compressed_X[x] = countX
    countX += 1

compressed_Y = {}
countY = 0
for y in yvalues:
    compressed_Y[y] = countY
    countY += 1

a = [[0 for j in range(countY + 1)] for i in range(countX + 1)]
for x1, y1, x2, y2 in Posters:
    x1 = compressed_X[x1]
    y1 = compressed_Y[y1]
    x2 = compressed_X[x2]
    y2 = compressed_Y[y2]
    a[x1 + 1][y1 + 1] += 1
    a[x2 + 1][y1 + 1] -= 1
    a[x1 + 1][y2 + 1] -= 1
    a[x2 + 1][y2 + 1] += 1

for x in range(1, countX + 1):
    for y in range(1, countY + 1):
        a[x][y] += a[x-1][y] + a[x][y-1] - a[x-1][y-1]

for x in range(1, countX + 1):
    for y in range(1, countY + 1):
        if (a[x][y] > 0):
            a[x][y] = (xvalues[x] - xvalues[x-1]) * (yvalues[y] - yvalues[y-1])

pref = [[0 for j in range(countY + 1)] for i in range(countX + 1)]
for x in range(1, countX + 1):
    for y in range(1, countY + 1):
        pref[x][y] = a[x][y] + pref[x-1][y] + pref[x][y-1] - pref[x-1][y-1]

answer = (10**100, 0, 0)
for x in xvalues:
    if (x + w not in xvaluess):
        continue
    for y in yvalues:
        if (y + h not in yvaluess):
            continue
        x1 = compressed_X[x]
        y1 = compressed_Y[y]
        x2 = compressed_X[x + w]
        y2 = compressed_Y[y + h]
        Area = pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1]
        answer = min(answer, (Area, y, x))
print(answer[0], answer[2], answer[1])

