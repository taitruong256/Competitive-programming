#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+9;

ll dp[130][130];
string s;

string bin(ll n)
{
    string ans;
    for (ll i=0; i<20; i++) if (n&(1LL<<i)) ans.push_back('1'); else ans.push_back('0');
    while (ans.size()<128) ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return " "+ans;
}

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll k, b; cin>>k>>b;
    s=bin(k);
    cout<<s<<endl;
    ll m=b;
    ll n=1, x=1;
    while (x<k) x*=2, ++n;
    cout<<n<<endl;
    
    m=m-n+1;
    for (ll j=1; j<=128; j++) dp[1][j]=s[j]-'0';
    for (ll i=1; i<=m; i++)
    {
        for (ll j=1; j<=128; j++) 
        {
            dp[i][j]=dp[i-1][j+1];
            if (s[j]=='0') dp[i][j]*=2;
            else dp[i][j]+=binpow(2, i-1, mod)-dp[i-1][j+1]+mod;
            dp[i][j]%=mod;
        }
    }

    for (ll i=1; i<=m; i++)
    {
        for (ll j=1; j<=128; j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    ll ans=0;
    for (ll i=1; i<=128; i++) ans=(ans+dp[m][i])%mod;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}