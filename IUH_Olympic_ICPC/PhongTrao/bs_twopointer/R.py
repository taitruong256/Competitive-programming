n=int(input())
a=[int(x) for x in input().split()]
a.sort()
a.append(int(1e18))
ans=0
for i in range(n):
    l=0; r=n; res=0
    while l<=r:
        mid=(l+r)//2
        if (a[mid]>a[i]+5): res=mid; r=mid-1
        else: l=mid+1
    ans=max(ans, res-i)
print(ans)
    