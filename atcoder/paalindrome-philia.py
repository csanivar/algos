S = input()
l = len(S)
res = 0
for i in range(0,l//2):
    if S[i] != S[l-1-i]:
        res += 1

print(res)
