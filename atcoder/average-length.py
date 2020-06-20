#!/usr/local/bin/python3
import math

def get_distance(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

N = int(input())
points = []
for i in range(N):
    p = str(input()).split(" ")
    points.append((int(p[0]), int(p[1])))

total_dist = 0
for i in range(N):
    for j in range(i,N):
        total_dist += get_distance(points[i], points[j])

print(2*total_dist/N)