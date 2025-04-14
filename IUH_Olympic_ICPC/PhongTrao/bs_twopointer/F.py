a=[0, 2]
i=5; x=2
while i+x<=int(1e9):
    x=i+x
    i=i+3
    a.append(x)
a.append(int(1e18))

for _ in range(int(input())):
    n=int(input())
    res=0
    l=0; r=len(a)-1; ans=0
    while 1==1:
        while l<=r:
            mid=(l+r)//2
            if (a[mid]>n): ans=mid; r=mid-1
            else: l=mid+1
        if (ans==1): break
        n=n-a[ans-1]
        res=res+1
    print(res)