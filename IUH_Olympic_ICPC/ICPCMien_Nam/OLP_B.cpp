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
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m, q, a[100005], b[100005], d[100005], tree[400005];

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=d[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=min(tree[id*2], tree[id*2+1]);
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return inf;
    if (u<=l && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return min(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];

    sort(b+1, b+m+1);
    for (ll i=1; i<=n; i++)
    {
        ll pos=upper_bound(b+1, b+m+1, a[i])-b, prev;
        if (pos!=1) prev=pos-1; else prev=pos;
        d[i]=min(abs(a[i]-b[pos]), abs(a[i]-b[prev]));
    }
    build(1, 1, n);
    while (q--)
    {
        ll l, r; cin>>l>>r;
        cout<<query(1, 1, n, l, r)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}