for _ in range(int(input())):
    n, p, k=map(int, input().split())
    s=" "+input()
    x, y=map(int, input().split())
    cnt=[0]*(n+1)
    for i in range(n, 0, -1):
        if i+k<=n: cnt[i]=cnt[i+k]+(s[i]=='0')
        else: cnt[i]=(s[i]=='0')
    
    ans=int(1e18)
    for i in range(p, n+1):
        ans=min(ans, cnt[i]*x+(i-p)*y)
    print(ans)
    