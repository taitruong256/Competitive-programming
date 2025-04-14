n, m=map(int, input().split(" "))
a=[int(x) for x in ('0 '+input()).split(" ")]
a.append(int(1e18))
b=[int(x) for x in input().split(" ")]
sum=[0]*(n+1)
for i in range(1, n+1): sum[i]=sum[i-1]+a[i]

for i in range(m):
    x=b[i]
    l=0; r=n; ans=0
    while l<=r:
        mid=(l+r)//2
        if a[mid]>x: ans=mid, r=mid-1
        else: l=mid+1
    print(ans, x-sum[ans-1])