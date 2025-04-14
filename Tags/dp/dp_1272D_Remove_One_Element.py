from random import randint
from turtle import right


n=int(input())
a=[int(x) for x in ("0 "+input()).split(" ")]
left=[1]*(n+5);
right=[1]*(n+5)
ans=0;
for i in range(n-1, 0, -1): 
    if (a[i+1]>a[i]): right[i]=right[i+1]+1;
ans=max(ans, max(right))
for i in range(2, n+1):
    if (a[i]>a[i-1]): left[i]=left[i-1]+1;
ans=max(ans, max(left))
for i in range(1, n-1): 
    if (a[i+2]>a[i]): ans=max(ans, left[i]+right[i+2])
print(ans)