inp = input().split(" ")
A = int(inp[0])
B = int(inp[1])
X = int(inp[2])
n = 0
for i in range(0, 18):
    ni = (X - B*i)//A
    if ni > n and i == len(str(ni)):
        n = ni
if len(str(n)) >= 10:
    n = 1000000000
print(n)