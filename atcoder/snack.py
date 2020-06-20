def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 

def lcm(a,b): 
    return (a*b) / gcd(a,b) 

arr = list(map(int, input().split()))
print(int(lcm(arr[0],arr[1])))