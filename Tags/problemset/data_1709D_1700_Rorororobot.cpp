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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll maxn = 2e5+5;
// ll sparse[20][maxn];
ll n, m, a[maxn], tree[4*maxn];

// ll query(ll l, ll r)
// {
//     ll d=log2(r-l+1);
//     return max(sparse[d][l], sparse[d][r-(1<<d)+1]);
// }

void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id]=max(tree[id*2], tree[id*2+1]);
}

ll getvalue(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return max(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++) cin>>a[i];
    // for (ll i=1; i<=m; i++) sparse[0][i]=a[i];
    // for (ll i=1; i<=18; i++)
        // for (ll j=1; j+(1<<i)-1<=m; j++) sparse[i][j]=max(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
    
    buildtree(1, 1, m);
    // for (ll i=1; i<=4*m; i++) cout<<tree[i]<<" "; cout<<endl;
    ll q; cin>>q;
    while (q--)
    {
        ll x1, y1, x2, y2, k; cin>>x1>>y1>>x2>>y2>>k;
        if (abs(x1-x2)%k!=0 || abs(y1-y2)%k!=0)
        {
            cout<<"NO\n";
            continue;
        }
        else 
        {
            if (y1>y2) swap(y1, y2);
            ll mx=(n-x1)/k*k+x1, d=log2(y2-y1+1);
            if (getvalue(1, 1, m, y1, y2)>=mx) cout<<"NO\n";
            else cout<<"YES\n";
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
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}