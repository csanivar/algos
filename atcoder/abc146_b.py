N = int(input())
S = input()
alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"
for s in S:
  i = alphas.index(s)
  print(alphas[i+N], end='')