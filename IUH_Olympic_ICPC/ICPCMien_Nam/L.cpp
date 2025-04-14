#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    while (true)
    {
        ll n; cin>>n;
        if (n==0) break;
        ll dp[n+5][5];
        for (ll i=0; i<=n+1; i++)
            for (ll j=0; j<=1; j++) dp[i][j]=0;
        string s1, s2, s3; cin>>s1>>s2>>s3;
        s1=" "+s1;
        s2=" "+s2;
        s3=" "+s3;
        for (ll i=n; i>=1; i--)
        {
            ll a=s1[i]-'0';
            ll b=s2[i]-'0';
            ll c=s3[i]-'0';
            if ((a+b)%10==c)    //khong nho
            {
                if (a+b<10)
                {
                    dp[i][0]=dp[i+1][0]+1;
                    dp[i][1]=dp[i+1][1];
                }
                else
                {
                    dp[i][0]=dp[i+1][0];
                    dp[i][1]=max(dp[i+1][0]+1, dp[i+1][1]);
                }
            }
            else if ((a+b+1)%10==c)
            {
                if (a+b+1<10)
                {
                    if (dp[i+1][1]>0) dp[i][0]=max(dp[i+1][1]+1, dp[i+1][0]);
                    else dp[i][0]=dp[i+1][0];
                    dp[i][1]=dp[i+1][1];
                }
                else
                {
                    dp[i][0]=dp[i+1][0];
                    if (dp[i+1][1]>0) dp[i][1]=dp[i+1][1]+1;
                    else dp[i][1]=dp[i+1][1];
                }
            }
            else
            {
                dp[i][0]=dp[i+1][0];
                dp[i][1]=dp[i+1][1];
            }
        }
        cout<<max(n-dp[1][0], n-dp[1][1])<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}