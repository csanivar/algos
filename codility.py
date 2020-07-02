import math

def getIndex(alpha):
    return ord(alpha) - ord('A')

def solution(S, X, Y):
    # write your code in Python 3.6
    first = [None]*26
    second = [None]*26
    N = len(S)
    for i in range(N):
        dist = math.sqrt((X[i]**2)+(Y[i]**2))
        idx = getIndex(S[i])
        if first[idx] == None:
            first[idx] = dist
        elif dist < first[idx]:
            second[idx] = first[idx]
            first[idx] = dist
        elif second[idx] == None or dist < second[idx]:
            second[idx] = dist

    min_sec = float('inf')
    for i in second:
        min_sec = i if i and i < min_sec else min_sec

    cnt = 0
    for i in first:
        if i and i < min_sec:
            cnt += 1


    return cnt

======================

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    cunt = 0
    for c in list(S):
        if c == 'a':
            cunt += 1

    if cunt % 3 != 0:
        return 0
    if cunt == 0:
        return ((len(S)-1)*(len(S)-2))//2

    share = cunt // 3
    start = []
    end = []
    cnt2 = 0
    for i, c in enumerate(list(S)):
        if c == 'a':
            if cnt2 == 0:
                start.append(i)
            cnt2 += 1
            if cnt2 == share:
                end.append(i)
                cnt2 = 0
    res = (start[1]-end[0])*(start[2]-end[1])

    return res
==========================

import math

def getNumLength(num):
    if num <= 1:
        return 0
    return len(str(num))

def getLength(pairs):
    length = 0
    for pair in pairs:
        length = length + 1 + getNumLength(pair[1])
    return length

def getRemovalNum(pairs, n, m):
    removed = 0
    i = n
    while(i <= m):
        removed = removed + 1 + getNumLength(pairs[i][1])
        i += 1


    if n - 1 >= 0 and m + 1 < len(pairs) and pairs[n - 1][0] == pairs[m + 1][0]:
        before = pairs[n - 1]
        after = pairs[m + 1]
        removed = removed + getNumLength(before[1]) + getNumLength(after[1]) - getNumLength(before[1] + after[1]) + 1
    return removed

def solution(S, K):
    # write your code in Python 3.6
    pairs = []
    cur = S[0]
    cnt = 0
    for c in S:
        if c == cur:
            cnt += 1
        else:
            pairs.append((cur, cnt))
            cur = c
            cnt = 1
    pairs.append((cur, cnt))

    best_removal = 0
    for i, pair in enumerate(pairs):
        removal = 0
        if pair[1] > K:
            continue
        elif pair[1] == K:
            continue
            # removal = getRemovalNum(pairs, i, i)
        else:
            remainder = K
            j = i
            while(j < len(pairs) and pairs[j][1] <= remainder):
                remainder = remainder - pairs[j][1]
                end = j
                j += 1

            if (j < len(pairs)):
                removal = removal + getRemovalNum(pairs, i, j - 1) + getNumLength(pairs[j][1]) - getNumLength(pairs[j][1] - remainder)
            else:
                removal = 0

        if removal > best_removal:
            best_removal = removal

    return getLength(pairs) - best_removal