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
ll n, m, a[maxn], tree[4*maxn], idx[maxn];

void build(ll id, ll l, ll r, ll level)
{
    if (l==r)
    {
        tree[id]=a[l];
        idx[l]=id;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid, level-1);
    build(id*2+1, mid+1, r, level-1);
    if (level%2==1) tree[id]=tree[id*2]|tree[id*2+1];
    else tree[id]=tree[id*2]^tree[id*2+1];
}

void update(ll pos, ll level, ll val)
{
    ll id=idx[pos];
    tree[id]=val;
    id/=2; 
    --level;
    while (id>0)
    {
        if ((n-level)%2==1) tree[id]=tree[id*2]|tree[id*2+1];
        else tree[id]=tree[id*2]^tree[id*2+1];
        --level;
        id/=2;
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=(1<<n); i++) cin>>a[i];
    build(1, 1, 1<<n, n);
    
    while (m--)
    {
        ll pos, val; cin>>pos>>val;
        update(pos, n, val);
        cout<<tree[1]<<endl;
        // for (ll i=1; i<=4*(1<<n); i++) cout<<tree[i]<<" "; cout<<endl;
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