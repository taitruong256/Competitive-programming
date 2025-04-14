n=int(input())
c=[int(x) for x in input().split(" ")]
s=[input() for x in range(n)]

INF=int(1e18)
dp=[[INF, INF] for x in range(0, n+1)]

dp[0][0]=0; dp[0][1]=c[0]

for i in range(1, n):
    x1=s[i-1]
    x2=s[i-1][::-1]
    y1=s[i]
    y2=s[i][::-1]
    if x1<=y1: dp[i][0]=min(dp[i][0], dp[i-1][0])
    if x1<=y2: dp[i][1]=min(dp[i][1], dp[i-1][0]+c[i])
    if x2<=y1: dp[i][0]=min(dp[i][0], dp[i-1][1])
    if x2<=y2: dp[i][1]=min(dp[i][1], dp[i-1][1]+c[i])
    
ans=min(dp[n-1][0], dp[n-1][1])
if ans==INF: print(-1)
else: print(ans)
