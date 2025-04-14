/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

ll n, a[300005], dp[300005][3], score[300005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll x=0;
    for (ll i=1; i<=n; i++)
    {
        if (a[i]>x) ++x;
        else if (a[i]<x) --x;
        score[i]=x;
    }

    for (ll i=1; i<=n; i++)
        if (a[i]>dp[i-1][0]) dp[i][0]=dp[i-1][0]+1;
        else if (a[i]==dp[i-1][0]) dp[i][0]=dp[i-1][0];
        else dp[i][0]=min(dp[i-1][0], a[i]);

    segment_tree seg(n);
    for (ll i=1; i<=n; i++)
    {
        ll mx=seg.query(1, 1, n, 1, i-1);
        if (a[i]>mx) mx=mx+1;
        else if (a[i]<mx) mx=a[i];
        dp[i][1]=mx;
        if (a[i]>dp[i-1][1]) dp[i][1]=max(mx, dp[i-1][1]+1);
        else if (a[i]==dp[i-1][1]) dp[i][1]=max(mx, dp[i-1][1]);
        else dp[i][1]=max(mx, dp[i-1][1]-1);
        seg.update(1, 1, n, i, score[i]);
    }

    // for (ll i=1; i<=n; i++) cout<<score[i]<<" "; cout<<endl;
    // for (ll j=0; j<=1; j++)
    // {
    //     for (ll i=1; i<=n; i++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // } 
    // cout<<endl;

    ll ans=0;
    for (ll i=1; i<=n-1; i++) ans=max(ans, score[i]);
    ans=max(ans, dp[n][1]);
    if (ans==n) --ans;
    cout<<ans<<endl;

    for (ll i=1; i<=n; i++)
    {
        score[i]=0;
        for (ll j=0; j<=1; j++) dp[i][j]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}