import math

N,M = map(int, input().split())
cities = list(map(int, input().split()))
towers = list(map(int, input().split()))

max_city = 0
ptr = 0
for city in cities:
    while ptr<M-1 and towers[ptr]<=city:
        ptr += 1
    left_dist = abs(towers[ptr-1] - city)
    right_dist = abs(towers[ptr] - city)
    min_tower = min(left_dist,right_dist)
    if min_tower > max_city:
        max_city = min_tower

print(max_city)
