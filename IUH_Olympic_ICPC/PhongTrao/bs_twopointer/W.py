for _ in range(int(input())):
    n, x, y=map(int, input().split(" "))
    a=[int(x) for x in input().split(" ")]
    a.append(int(1e18))
    a.sort()
    ans=0
    for i in range(n):
        l=i+1; r=n+1; ans1=i+1
        while (l<=r):
            mid=(l+r)//2
            if a[mid]>=x-a[i]: ans1=mid; r=mid-1
            else: l=mid+1
        
        l=i+1; r=n+1; ans2=i+1
        while (l<=r):
            mid=(l+r)//2
            if a[mid]>y-a[i]: ans2=mid; r=mid-1
            else: l=mid+1
            
        ans=ans+(ans2-ans1)
    print(ans)
            