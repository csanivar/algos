#!/usr/local/bin/python3
import sys
sys.setrecursionlimit(10000)
s = input().split()
dest = (int(s[0]), int(s[1]))
MOD = 10**9 + 7

def find_steps(src, dest):
    if src[0]>dest[0] or src[1]>dest[1]:
        return 0
    if src[0]==dest[0] and src[1]==dest[1]:
        return 1
    else:
        src1 = (src[0]+1, src[1]+2)
        src2 = (src[0]+2, src[1]+1)
        return find_steps(src1, dest)%MOD + find_steps(src2, dest)%MOD

print(find_steps((0,0), dest))