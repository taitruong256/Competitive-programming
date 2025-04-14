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

ll n, m, l[300005], cnt[300005], len=0, f[300005];
vector<ll> nxt[300005], pre[300005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
    {
        cin>>l[i];   
        len+=l[i];
        for (ll j=0; j<l[i]; j++)
        {
            ll x; cin>>x;
            if (x<=l[i]+1) ++cnt[x];
        }
        ll mex1=0;
        while (cnt[mex1]!=0) ++mex1;
        ll mex2=mex1+1;
        while (cnt[mex2]!=0) ++mex2;
        nxt[mex1].push_back(mex2);
        pre[mex2].push_back(mex1);
        for (ll j=0; j<=l[i]+1; j++) cnt[j]=0; 
    }


    for (ll i=len+1; i>=0; i--)
    {
        f[i]=max(f[i], i);
        for (auto j: nxt[i]) f[i]=max(f[i], f[j]);
    }
    
    segment_tree seg(len+5);
    for (ll i=0; i<=len+1; i++) if (nxt[i].size()>1) seg.update(1, 0, len+1, i, f[i]);
    for (ll i=len+1; i>=0; i--)
    {
        f[i]=max(f[i], seg.query(1, 0, len+1, 0, i));
        for (auto j: nxt[i]) f[i]=max(f[i], seg.query(1, 0, len+1, i, j));
        for (auto j: pre[i]) 
        {
            f[j]=max(f[j], f[i]);
            seg.update(1, 0, len+1, j, f[j]);
        }
    }

   
    ll ans=0;
    for (ll i=0; i<=min(m, len); i++) ans+=f[i];
    if (m>len) ans+=m*(m+1)/2-len*(len+1)/2;
    cout<<ans<<endl;


    for (ll i=len+1; i>=0; i--) 
    {
        nxt[i].clear();
        pre[i].clear();
        f[i]=0;
    }
    len=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}