/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
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
ll n, q;
ll tree_l[800005], tree_r[800005], a[200005];
map<ll, ll> idx;

void pull(ll id)
{
    tree_l[id]=min(tree_l[id*2], tree_l[id*2+1]);
    tree_r[id]=min(tree_r[id*2], tree_r[id*2+1]);
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree_l[id]=a[l]+(n-l+1);
        tree_r[id]=a[l]+l;
        idx[l]=id;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    pull(id);
}

void update(ll pos, ll val)
{
    ll id=idx[pos];
    tree_l[id]=val+(n-pos+1);
    tree_r[id]=val+pos;
    
    id/=2;
    while (id>0)
    {
        pull(id);
        id/=2;
    }
}

ll query(ll type, ll id, ll l, ll r, ll u, ll v)
{
    //0 tim ben trai
    //1 tim ben phai
    if (r<u || l>v) return inf;
    if (u<=l && r<=v) return type==0? tree_l[id]: tree_r[id];
    ll mid=(l+r)/2;
    return min(query(type, id*2, l, mid, u, v), query(type, id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll pos, val; cin>>pos>>val;
            update(pos, val);
        }
        else 
        {
            ll pos; cin>>pos;
            ll left=query(0, 1, 1, n, 1, pos)-(n-pos+1);
            ll right=query(1, 1, 1, n, pos, n)-pos;
            cout<<min(left, right)<<endl;
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