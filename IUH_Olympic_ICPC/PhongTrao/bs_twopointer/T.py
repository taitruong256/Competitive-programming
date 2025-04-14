n, k=map(int, input().split())
a=[int(x) for x in ('0 '+input()).split()]
sum=[0]*(n+1)
for i in range(1, n+1): sum[i]=sum[i-1]+a[i]
sum.append(int(1e18))
# print(a)
# print(sum)
res=0
for i in range(1, n+1):
    l=i; r=n+1; ans=i
    while l<=r:
        mid=(l+r)//2
        if sum[mid]-sum[i-1]>k: ans=mid; r=mid-1;
        else: l=mid+1
    res=max(res, ans-i)
    # print(i, ans)
print(res)
