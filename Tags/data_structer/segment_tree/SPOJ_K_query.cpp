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

struct segment_tree_vector
{
    ll n;
    vector<ll> arr;
    vector<vector<ll>> tree;
    segment_tree_vector(){}
    segment_tree_vector(ll _n, vector<ll> _arr)
    {
        n=_n;
        arr=_arr;
        tree.resize(4*n+5);
        build(1, 1, n);
    }
    vector<ll> opt(vector<ll> a, vector<ll> b)
    {
        ll i=0, j=0;
        vector<ll> v;
        while (i<a.size() && j<b.size())
        {
            if (a[i]<b[j]) v.push_back(a[i++]);
            else v.push_back(b[j++]);
        }
        while (i<a.size()) v.push_back(a[i++]);
        while (j<b.size()) v.push_back(b[j++]);
        return v;
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id].push_back(arr[l]);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
    ll query(ll id, ll l, ll r, ll u, ll v, ll k)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].size()-(upper_bound(tree[id].begin(), tree[id].end(), k)-tree[id].begin());
        ll mid=(l+r)/2;
        return query(id*2, l, mid, u, v, k)+query(id*2+1, mid+1, r, u, v, k);
    }
};

void solve()
{
    ll n; cin>>n;
    vector<ll> v(n+5);
    for (ll i=1; i<=n; i++) cin>>v[i];
    segment_tree_vector seg(n, v);
    ll q; cin>>q;
    while (q--)
    {
        ll l, r, k; cin>>l>>r>>k;
        cout<<seg.query(1, 1, n, l, r, k)<<endl;
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