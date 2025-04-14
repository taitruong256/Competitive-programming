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
const ll mod = 998244353;
ll n, q, x[500005], lazya[2000005], lazyb[2000005], seg[2000005];

void down(ll id, ll l, ll r)
{
    if (lazya[id]!=1 && lazyb[id]!=0)
    {
        seg[id]=(seg[id]*lazya[id]+(r-l+1)*lazyb[id])%mod;  //lưu ý tổng cộng thêm (r-l+1)*b
        if (l!=r)
        {
            lazya[id*2]=(lazya[id*2]*lazya[id])%mod;
            lazyb[id*2]=(lazyb[id*2]*lazya[id]+lazyb[id])%mod;
            lazya[id*2+1]=(lazya[id*2+1]*lazya[id])%mod;
            lazyb[id*2+1]=(lazyb[id*2+1]*lazya[id]+lazyb[id])%mod;
        }
        lazya[id]=1;
        lazyb[id]=0;
    }
}

void build(ll id, ll l, ll r)
{
    lazya[id]=1;
    lazyb[id]=0;
    if (l==r)
    {
        seg[id]=x[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id]=(seg[id*2]+seg[id*2+1])%mod;
}

void update(ll id, ll l, ll r, ll u, ll v, ll a, ll b)
{
    down(id, l, r);
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        lazya[id]=(lazya[id]*a)%mod;
        lazyb[id]=(lazyb[id]*a+b)%mod;
        down(id, l, r);
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, u, v, a, b);
    update(id*2+1, mid+1, r, u, v, a, b);
    seg[id]=(seg[id*2]+seg[id*2+1])%mod;
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    down(id, l, r);
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return seg[id];
    ll mid=(l+r)/2;
    return (query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v))%mod;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>x[i];
    build(1, 1, n);
    while (q--)
    {
        ll type; cin>>type; 
        if (type==0)
        {
            ll l, r, a, b; cin>>l>>r>>a>>b; ++l;
            update(1, 1, n, l, r, a, b);
        }
        else 
        {
            ll l, r; cin>>l>>r; ++l;
            cout<<query(1, 1, n, l, r)<<endl;
        }
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