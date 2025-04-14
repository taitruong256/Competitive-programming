n=int(input())
a=[int(x) for x in ("0 "+input()).split(" ")]
a.sort()
q=int(input())
for _ in range(q):
    x=int(input())
    l=0; r=n; ans=0;
    while l<=r:
        mid=(l+r)//2
        if a[mid]<=x: ans=mid; l=mid+1;
        else: r=mid-1
    if (x<a[1]): print(0)
    else: print(ans)
    
