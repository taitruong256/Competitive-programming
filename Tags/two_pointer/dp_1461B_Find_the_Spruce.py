for _ in range(int(input())):
    n, m=map(int, input().split(" "))
    s=[]
    for i in range(n): s.append(input())
    dp=[]
    for i in range(n): dp.append([0]*m)
    ans=0
    for i in range(n-1, -1, -1):
        for j in range(m-1, -1, -1):
            if i==n-1:
                dp[i][j]=(s[i][j]=='*')
            else:
                if j==0 or j==m-1:
                    dp[i][j]=(s[i][j]=='*')
                else:
                    if s[i][j]=='*':
                        dp[i][j]=min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1])
                        dp[i][j]+=(s[i][j]=='*')
            ans+=dp[i][j]  
    print(ans)         