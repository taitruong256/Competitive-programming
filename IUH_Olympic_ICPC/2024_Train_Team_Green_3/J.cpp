#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 998244353;

ll n, m, dp[250005][505], used[250005];
vector<ll> v;
ll ans=0;

ll calc_dp(ll turn, ll idx)   //luot thu turn chon la bai thu idx 
{
    cout<<turn<<" "<<idx<<"    ";
    v.push_back(idx);
    for (auto i: v) cout<<i<<" "; cout<<endl;
    if (v.size()==n*m) ++ans;
    // for (ll i=1; i<=n*m; i++) cout<<used[i]<<" "; cout<<endl;
    // if (v.size()==n*m) return 1;
    // if (dp[turn][idx]!=-1) return dp[turn][idx];
    used[idx]=1;    

    ll res=0;
    if (turn%2==1)
    {
        for (ll i=1; i<=n*m; i++) if (used[i]==0)
        {
            ll a=(idx-1)/m+1, b=(idx-1)%m+1;
            ll c=(i-1)/m+1, d=(i-1)%m+1;
            bool check=0;
            if (a==1 && c!=1) check=1;
            if (a==c && b>d) check=1;
            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<check<<endl;
            if (check==1)
            {
                // cout<<"ok"<<endl;
                res=(res+calc_dp(turn+1, i))%mod;
            } 
        }
    }
    else 
    {
        for (ll i=1; i<=n*m; i++) if (used[i]==0)
        {
            res=(res+calc_dp(turn+1, i))%mod;
        }
    }
    used[idx]=0;
    v.pop_back();
    return res;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=250000; i++)
        for (ll j=1; j<=500; j++)
            dp[i][j]=-1;
    
    for (ll i=1; i<=n*m; i++) 
    {
        // cout<<"------------"<<i<<"---------------"<<endl;
        calc_dp(1, i);
    }
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