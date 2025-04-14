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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;

struct segment_tree_2D
{
    ll n, m;
    vector<vector<ll>> tree;

    segment_tree_2D(){}
    segment_tree_2D(ll _n, ll _m)
    {
        n=_n; m=_m;
        tree.resize(4*n+5);
        for (ll i=0; i<=4*n; i++) tree[i].resize(4*m+5);
    }

    void update_y(ll idx, ll lx, ll rx, ll idy, ll ly, ll ry, ll u, ll v, ll val)
    {  
        if (ly==ry)
        {
            if (lx==rx) tree[idx][idy]=val;
            else tree[idx][idy]=tree[idx*2][idy]+tree[idx*2+1][idy];
            return;
        }
        ll midy=(ly+ry)/2;
        if (v<=midy) update_y(idx, lx, rx, idy*2, ly, midy, u, v, val);
        else update_y(idx, lx, rx, idy*2+1, midy+1, ry, u, v, val);
        tree[idx][idy]=tree[idx][idy*2]+tree[idx][idy*2+1];
    }

    void update_x(ll idx, ll lx, ll rx, ll u, ll v, ll val)
    {    
        if (lx!=rx) 
        {
            ll midx=(lx+rx)/2;
            if (u<=midx) update_x(idx*2, lx, midx, u, v, val);
            else update_x(idx*2+1, midx+1, rx, u, v, val);
        }
        update_y(idx, lx, rx, 1, 1, m, u, v, val);
    }  
 
    void update(ll x, ll y, ll val)
    {
        update_x(1, 1, n, x, y, val);
    }

    ll query_y(ll idx, ll idy, ll ly, ll ry, ll y1, ll y2)
    {
        if (y1>y2) return 0;
        if (ly>y2 || ry<y1) return 0;
        if (y1<=ly && ry<=y2) return tree[idx][idy];
        ll midy=(ly+ry)/2;
        return query_y(idx, idy*2, ly, midy, y1, y2)+query_y(idx, idy*2+1, midy+1, ry, y1, y2);
    }

    ll query_x(ll idx, ll lx, ll rx, ll x1, ll y1, ll x2, ll y2)
    {
        if (x1>x2) return 0;
        if (lx>x2 || rx<x1) return 0;
        if (x1<=lx && rx<=x2) return query_y(idx, 1, 1, m, y1, y2);
        ll midx=(lx+rx)/2;
        return query_x(idx*2, lx, midx, x1, y1, x2, y2)+query_x(idx*2+1, midx+1, rx, x1, y1, x2, y2);
    }

    ll query(ll x1, ll y1, ll x2, ll y2)
    {
        return query_x(1, 1, n, x1, y1, x2, y2);
    }
};

segment_tree_2D seg;
ll n, q, c[1005][1005];

void solve()
{
    cin>>n>>q;
    seg=segment_tree_2D(n, n);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            char x; cin>>x;
            if (x=='*') c[i][j]=1, seg.update_x(1, 1, n, i, j, 1);
            else c[i][j]=0;
        }
    
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll x, y; cin>>x>>y;
            seg.update(x, y, 1-c[x][y]);
            c[x][y]=1-c[x][y];
        }
        else 
        {
            ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            cout<<seg.query(x1, y1, x2, y2)<<endl;
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