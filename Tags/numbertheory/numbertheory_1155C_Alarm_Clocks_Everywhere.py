from math import gcd
n, m=map(int, input().split(" "))
x=[int(x) for x in input().split(" ")]
p=[int(x) for x in input().split(" ")]
g=x[1]-x[0]
for i in range(2, n): g=gcd(g, x[i]-x[i-1])
for i in range(m): 
    if g%p[i]==0: 
        print("YES")
        print(x[0], i+1)
        exit(0)
print("NO")
