n=int(input())
a=[int(x) for x in input().split(" ")]
sum=[0]*(n+5)
sum[n+1]=int(1e18)
for i in range(1, n+1): sum[i]=sum[i-1]+a[i-1]
m=int(input())
q=[int(x) for x in input().split(" ")]
for i in range(m):
    x=int(q[i])
    l=0; r=n+1; ans=1
    while l<=r:
        mid=(l+r)//2
        if (sum[mid]>=x): 
            ans=mid
            r=mid-1
        else: l=mid+1
    print(ans)
