for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in ("0 "+input()).split(" ")]
    a.append(-a[-1])
    ans=0
    mx=a[1]
    for i in range(2, n+2):
        if (a[i]<0)==(a[i-1]<0): mx=max(mx, a[i])
        else: 
            ans=ans+mx
            mx=a[i]
    print(ans)