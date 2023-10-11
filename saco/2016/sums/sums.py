n = int(input())

def bit_count(x):
    ans, i = 0, 1
    while i < x:
        if (x & i):
            ans += 1
        i >>= 1
    return ans

if (bit_count(x) == 1):
    print(-1)
else:
    for k in range(2, n+1):
        if not (n - k * (k - 1) // 2) % k:
            break

    #k = T-S+1
    S = (n - k * (k - 1) // 2) // k
    T = k + S - 1

    if ((S <= 0) or (T <= 0)):
        print(-1)
    else:
        print(S, T)
