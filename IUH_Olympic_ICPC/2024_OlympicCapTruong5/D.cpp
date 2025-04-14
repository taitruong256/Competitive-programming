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

ll n, maxh;
ll score[3000005], h1[1000005], h2[1000005], h3[1000005];

struct segment_tree
{
    ll n;
    vector<ll> tree;

    segment_tree(){}
    void init(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=1;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
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
        if (pos<=mid) update(id*2, l, mid, pos, v);
        else update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }

    ll pos(ll id, ll l, ll r, ll val)
    {
        if (l==r) return l;
        ll mid=(l+r)/2;
        if (val<=tree[id*2]) return pos(id*2, l, mid, val);
        return pos(id*2+1, mid+1, r, val-tree[id*2]);
    }
};
segment_tree seg;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        cin>>h1[i];
        score[1]+=1;
        score[h1[i]+1]-=1;
    }
    for (ll i=1; i<=n; i++) 
    {
        cin>>h2[i];
        score[h1[i]+1]+=2;
        score[h1[i]+h2[i]+1]-=2;
    }
    for (ll i=1; i<=n; i++) 
    {
        cin>>h3[i];
        score[h1[i]+h2[i]+1]+=5;
        score[h1[i]+h2[i]+h3[i]+1]-=5;
    }
    for (ll i=1; i<=1300000; i++) score[i]+=score[i-1];
    // for (ll i=1; i<=n; i++) cout<<score[i]<<" "; cout<<endl;
    
    ll q; cin>>q;
    seg.init(1300000);
    while (q--)
    {
        ll h, p=0; cin>>h;
        p=seg.pos(1, 1, 1300000, h);  
        cout<<score[p]<<endl;
        seg.update(1, 1, 1300000, p, 0);
    }
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