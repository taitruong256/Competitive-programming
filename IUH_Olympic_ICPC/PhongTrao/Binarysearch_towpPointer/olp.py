import math
l, r, a, k = map(int, input().split())
l=l*a;
r=r*a;
k=(a*k)//math.gcd(a, k);
l=(l+k-1)//k*k;
r=(r//k)*k;
if (l>r): print(0)
else: print((r-l)//k+1)