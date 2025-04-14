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

struct fenwick2D
{
    vector<vector<ll>> bit;
    ll n, m;
    fenwick2D() {}
    fenwick2D(ll _n, ll _m)
    {
        n=_n; m=_m;
        bit.resize(n+5);
        for (ll i=0; i<=n; i++) bit[i].resize(m+5, 0);
    }
    void update(ll x, ll y, ll val)
    {
        for (ll i=x; i<=n; i+=-i&i) 
            for (ll j=y; j<=m; j+=-j&j)
                bit[i][j]+=val;
    }
    ll query(ll x, ll y)
    {
        ll ans=0;
        for (ll i=x; i>0; i-=-i&i)
            for (ll j=y; j>0; j-=-j&j)
                ans+=bit[i][j];
        return ans;
    }
    ll query(ll x1, ll y1, ll x2, ll y2)
    {
        ll ans=0;
        ans+=query(x2, y2);
        ans-=query(x1-1, y2);
        ans-=query(x2, y1-1);
        ans+=query(x1-1, y1-1);
        return ans;
    }
};

ll n, q;
fenwick2D ft(1000, 1000);
ll c[1005][1005];

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) 
        {
            char x; cin>>x;
            if (x=='.') c[i][j]=0;
            else c[i][j]=1, ft.update(i, j, 1);
        }
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll x, y; cin>>x>>y;
            ft.update(x, y, 1-2*c[x][y]);
            c[x][y]=1-c[x][y];
        }
        else 
        {
            ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            cout<<ft.query(x1, y1, x2, y2)<<endl;
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