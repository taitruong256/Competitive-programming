#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
ld dp[105][105], a[105];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i], a[i]*=0.01;
    sort(a+1, a+n+1, greater<ld>());
    ld ans=0;
    dp[0][0]=1;
    for (ll k=1; k<=n; k++)
    {
        for (ll j=0; j<=k; j++)
        {
            for (ll i=0; i<k; i++)
                if (j>=1)
                    dp[k][j]=dp[i][j-1]*a[k]+dp[i][j]*(1.0-a[k]);
                else 
                    dp[k][j]=dp[i][j]*(1.0-a[k]);
        }
        ld res=0;
        for (ll j=1; j<=k; j++)
            res+=dp[k][j]*pow(j, 1.0*j/k);
        // cout<<fixed<<setprecision(9)<<res<<endl;
        ans=max(ans, res);
    }

    for (ll i=0; i<=n; i++)
    {
        for (ll j=0; j<=i; j++)
        {
            cout<<fixed<<setprecision(9)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<fixed<<setprecision(9)<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}