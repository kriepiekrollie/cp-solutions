n = int(input())
banner = sorted([tuple(map(int, input().split())) for i in range(n)])

nailed = [False for i in range(n)]
nails = []
k = 0
for i in range(n - 1, -1, -1):
    if (not nailed[i]):
        k += 1
        nails.append(banner[i][0])
        for j in range(i, -1, -1):
            if (banner[j][1] < banner[i][0]):
                break
            nailed[j] = True

print(k)
print(*sorted(nails))
