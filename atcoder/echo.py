N = int(input())
S = input()
h = int(N/2)
if S[0:h] == S[h:N]:
    print("Yes")
else:
    print("No")
