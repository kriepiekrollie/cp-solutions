N, W = map(int, input().split())
trees = []

xvals = {0, W}
yvals = {0, W}
for _ in range(N):
    x, y = map(int, input().split())
    if (x != 0 and x != W and y != 0 and y != W):
        trees.append((x, y))
        xvals.add(x)
        yvals.add(y)
N = len(trees)

# Coordinate compression
big_x = sorted(list(xvals))
small_x = {}
for i, x in enumerate(big_x):
    small_x[x] = i + 1
num_x = len(big_x)
big_x = [0] + big_x + [W]

big_y = sorted(list(yvals))
small_y = {}
for i, y in enumerate(big_y):
    small_y[y] = i + 1
num_y = len(big_y)
big_y = [0] + big_y + [W]

num_trees = [0 for i in range(5 * num_y)]
first_non_zero = [W + 1 for i in range(5 * num_y)]
last_non_zero = [-1 for i in range(5 * num_y)]
ans = [0 for i in range(5 * num_y)]

def combine(v, tl, tm, tr):
    num_trees[v] = num_trees[2 * v] + num_trees[2 * v + 1]

    if (first_non_zero[2 * v] <= W):
        first_non_zero[v] = first_non_zero[2 * v]
    else:
        first_non_zero[v] = first_non_zero[2 * v + 1]

    if (last_non_zero[2 * v + 1] >= 0):
        last_non_zero[v] = last_non_zero[2 * v + 1]
    else:
        last_non_zero[v] = last_non_zero[2 * v]

    ans[v] = max(ans[2 * v], ans[2 * v + 1])
    ans[v] = max(ans[v], min(big_y[tr], first_non_zero[2 * v + 1]) - max(big_y[tl], last_non_zero[2 * v]))

def build(v, tl, tr):
    if (tl == tr):
        num_trees[v] = 0
        first_non_zero[v] = W + 1
        last_non_zero[v] = -1
        ans[v] = 0
        return

    tm = (tl + tr) // 2
    build(2 * v, tl, tm)
    build(2 * v + 1, tm + 1, tr)
    combine(v, tl, tm, tr)

def add(v, tl, tr, idx, delta):
    if (tl == tr):
        num_trees[v] += delta
        if (num_trees[v] > 0):
            first_non_zero[v] = big_y[idx]
            last_non_zero[v] = big_y[idx]
        else:
            first_non_zero[v] = W + 1
            last_non_zero[v] = -1 
        ans[v] = 0
        return

    tm = (tl + tr) // 2
    if (idx <= tm):
        add(2 * v, tl, tm, idx, delta)
    else:
        add(2 * v + 1, tm + 1, tr, idx, delta)
    combine(v, tl, tm, tr)
        
build(1, 1, num_y)
add(1, 1, num_y, 1, +1)
add(1, 1, num_y, num_y, +1)

# Sort trees by x-value
trees = sorted(trees)

# At each step in the algorithm, we have the trees with xvalues [xl, xr)
i, j = 0, 0
l, r = 1, 1
result = 0
while (l <= num_x):
    r = max(l, r)
    while (r <= num_x):

        width = big_x[r] - big_x[l-1]
        height = ans[1]

        result = max(result, min(height, width))
        if (height < width):
            break

        xr = big_x[r]
        # Add trees with x value <= xr.
        while (j < N and trees[j][0] <= xr):
            y = small_y[trees[j][1]]
            add(1, 1, num_y, y, +1)
            j += 1
        r += 1

    xl = big_x[l]
    while (i < N and trees[i][0] <= xl):
        # Remove tree i.
        y = small_y[trees[i][1]]
        add(1, 1, num_y, y, -1)
        i += 1
    l += 1
print(result)
