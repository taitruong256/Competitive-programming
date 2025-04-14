from operator import le


n=int(input())
a=[int(x) for x in ("0 "+input()+" 0").split(" ")]
a[0]=int(1e10)
a[n+1]=int(-1e10)
print(a)

left=[1]*(n+5)
right=[1]*(n+5)
ans=0
for i in range(1, n+1):
    if a[i]>a[i-1]: left[i]=left[i-1]+1
for i in range(n, 0, -1):
    if a[i]<a[i+1]: right[i]=right[i+1]+1

ans=max(left)
ans=max(right)
for i in range(2, n):
    # print(i)
    if a[i-1]+1<a[i+1]: 
        ans=max(ans, left[i-1]+right[i+1]+1)
print(ans)
    