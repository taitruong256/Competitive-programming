from math import gcd
n=int(input())
a=[int(x) for x in input().split(" ")]
b=[int(x) for x in input().split(" ")]
cnt={0:0}
d=0

for i in range(n):
    if a[i]==0 and b[i]==0: d=d+1
    elif a[i]!=0:
        x=-b[i]//gcd(a[i], b[i])
        y=a[i]//gcd(a[i], b[i])
        if (y<0):
            x=-x
            y=-y
        if (x, y) not in cnt: cnt[(x, y)]=0
        cnt[(x, y)]=cnt[(x, y)]+1
print(d+max(cnt.values()))
    