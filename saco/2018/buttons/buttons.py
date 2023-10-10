A, N, M = map(int, input().split())

count = 0
while M > N:
    inc = A - (M % A)

    count += inc
    M += inc

    count += 1
    M //= A

print(count + (N - M))
