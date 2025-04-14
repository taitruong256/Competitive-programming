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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

ll n, q, a[100005];
map<ll, ll> seg[400005]; 

map<ll, ll> merges(map<ll, ll> a, map<ll, ll> b)
{
    if (a.size()<b.size()) swap(a, b);
    for (auto i: b) a[i.first]+=i.second;
    return a;
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        seg[id][a[l]]++;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id]=merges(seg[id*2], seg[id*2+1]);
}

map<ll, ll> get(ll id, ll l, ll r, ll u, ll v)
{
    map<ll, ll> tam;
    if (l>v || r<u) return tam;
    if (u<=l && r<=v) return seg[id];
    ll mid=(l+r)/2;
    return merges(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll l, r; cin>>l>>r;
        map<ll, ll> cnt=get(1, 1, n, l, r);
        bool check=false;
        for (auto i: cnt) if (i.second>(r-l+1)/2) check=true;
        if (check==true) cout<<"YES\n";
        else cout<<"NO\n";
        // for (auto i: cnt) cout<<i.first<<" "<<i.second<<"   "; cout<<endl;
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