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
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
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
const ll mod = 1e9+7, inf = 1e16;
ll n, q, a[100005];
vector<ll> tree[400005]; 

vector<ll> merge(vector<ll> a, vector<ll> b)
{
    vector<ll> c;
    ll n=a.size(), m=b.size(), i=0, j=0;
    while (i<n && j<m)
    {
        if (a[i]<b[j]) c.push_back(a[i]), ++i;
        else c.push_back(b[j]), ++j;
    }
    while (i<n) c.push_back(a[i]), ++i;
    while (j<m) c.push_back(b[j]), ++j;
    return c;
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id].push_back(a[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=merge(tree[id*2], tree[id*2+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v, ll k)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return upper_bound(tree[id].begin(), tree[id].end(), k)-tree[id].begin();
    ll mid=(l+r)/2;
    return get(id*2, l, mid, u, v, k)+get(id*2+1, mid+1, r, u, v, k);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll l, r, k; cin>>l>>r>>k;
        ll left=1, right=1e9, ans=1;
        while (left<=right)
        {
            ll mid=(left+right)/2;
            if (get(1, 1, n, l, r, mid)>=k) ans=mid, right=mid-1;
            else left=mid+1;
        }
        cout<<ans<<endl;
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