from math import floor

N,M = map(int,input().split())

def binomialCoeff(x,n,k):
    sum = 0
    term = 1
    i= 1
    while i<=n and sum<k:
        term *= x - i + 1
        term /= i
        sum += term
        i+=1
    return sum

def mllrials(n,k):
    low = 1
    high = k
    while low < high:
        mid = (low + high) // 2
        if binomialCoeff(mid, n, k) < k:
            low = mid + 1
        else:
            high = mid
    return low

print(floor(mllrials(M, N)))
