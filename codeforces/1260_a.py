n = int(input())
for i in range(n):
    (c, s) = map(lambda x: int(x), input().split(" "))
    a = s//c
    b = s%c
    res = (b*((a+1)**2))+(c-b)*(a**2)
    print(res)
