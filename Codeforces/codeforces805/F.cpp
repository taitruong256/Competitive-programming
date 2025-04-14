/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n, q;
map<ll, vector<ll>> tree;
vector<pair<ll, ll>> a;
 
vector<ll> merge(vector<ll> a, vector<ll> b)
{
    ll i=0, j=0;
    vector<ll> ans;
    while (i<a.size() && j<b.size())
    {
        if (a[i]<b[j]) 
        {
            ans.push_back(a[i]);
            ++i;
        }
        else
        {
            ans.push_back(b[j]);
            ++j;
        }
    }
    while (i<a.size()) ans.push_back(a[i]), ++i;
    while (j<b.size()) ans.push_back(b[j]), ++j;
    // for (auto it: ans) cout<<it<<" "; cout<<endl;
    return ans;
}
 
void build_tree(ll id, ll l, ll r) 
{
    if (l == r) {
        tree[id].push_back(a[l].first);
        return ;
    }
    ll mid = (l + r) / 2;
    build_tree(id*2, l, mid);
    build_tree(id*2+1, mid+1, r);
 
    tree[id]=merge(tree[id*2], tree[id*2+1]);
}
 
ll get_value(ll id, ll l, ll r, ll u, ll v, ll k) 
{
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) 
        return tree[id].size() - (upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin());
    ll mid = (l + r) / 2;
    return get_value(id*2, l, mid, u, v, k) + get_value(id*2+1, mid+1, r, u, v, k);
}
 
void solve()
{
    cin>>n;
    a.clear();
    a.push_back({0, 0});
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        if (x<i) a.push_back({x, i});
    }
    tree.clear();
    n=a.size()-1;
    if (n==0)
    {
        cout<<0<<endl;
        return;
    }
    build_tree(1, 1, a.size()-1);
    long long ans=0;
    for (ll i=1; i<=n-1; i++)
    {
        ans+=get_value(1, 1, n, i+1, n, a[i].second);
    }
    cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}