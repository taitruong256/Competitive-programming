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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

ll n, q, a[200005], seg[800005], lazy1[800005], lazy2[800005];

ll sum(ll l, ll r)
{
    return r*(r+1)/2-(l-1)*l/2;
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        seg[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id]=seg[id*2]+seg[id*2+1];
}

void down(ll id, ll l, ll r)
{
    if (lazy1[id]!=0)
    {
        seg[id]+=lazy1[id]*(r-l+1);
        if (l!=r)
        {
            lazy1[id*2]+=lazy1[id];
            lazy1[id*2+1]+=lazy1[id];
        }
        lazy1[id]=0;
    }
    if (lazy2[id]!=0)
    {
        seg[id]+=lazy2[id]*sum(l, r);
        if (l!=r)
        {
            lazy2[id*2]+=lazy2[id];
            lazy2[id*2+1]+=lazy2[id];
        }
        lazy2[id]=0;
    }
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    down(id, l, r);
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        lazy1[id]+=val;
        lazy2[id]+=1;
        down(id, l, r);
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    seg[id]=seg[id*2]+seg[id*2+1];
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    down(id, l, r);
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return seg[id];
    ll mid=(l+r)/2;
    return query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll type, l, r; cin>>type>>l>>r;
        if (type==1) update(1, 1, n, l, r, -(l-1));
        else cout<<query(1, 1, n, l, r)<<endl;
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