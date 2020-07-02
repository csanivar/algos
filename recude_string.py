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
