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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'

multiset<ll> tree[400005];
ll a[400005];
const ll inf = INT_MAX;

inline ll query(ll id, ll l, ll r, ll &u, ll &v, ll &k)   //so lon hon hoac bang k trong doan [l, r]
{
    if (l>v || r<u) return inf;
    if (u<=l && r<=v)
    {
        auto it=tree[id].lower_bound(k);
        if (it==tree[id].end()) return inf;
        return *it;
    }
    ll mid=(l+r)>>1;
    return min(query(id<<1, l, mid, u, v, k), query((id<<1)|1, mid+1, r, u, v, k));
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id].insert(a[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=tree[id*2];
    for (ll i: tree[id*2+1]) tree[id].insert(i);
}

inline void update(ll id, ll l, ll r, ll &pos, ll &v1, ll &v2)
{
    if (l>pos || r<pos) return;
    tree[id].erase(tree[id].find(v1));
    tree[id].insert(v2);
    if (l==r) return;
    ll mid=(l+r)>>1;
    if (pos<=mid) update(id<<1, l, mid, pos, v1, v2);
    else update((id<<1)|1, mid+1, r, pos, v1, v2);
}

void solve()
{
    ll n, q; cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll pos, val; cin>>pos>>val;
            update(1, 1, n, pos, a[pos], val);
            a[pos]=val;
        }
        else 
        {
            ll l, r, k; cin>>l>>r>>k;
            ll ans=query(1, 1, n, l, r, k);
            if (ans==inf) ans=-1;
            cout<<ans<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
