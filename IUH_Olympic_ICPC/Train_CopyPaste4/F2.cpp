/*=====================================================================================
                   IF YOU CAN POSSIABLE, THEN I ALSO CAN POSSIBALE                     
=====================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MOD=1e9+7;
const ll INF=1e5+7;
const ll MIN=- 1e5+7;
const ll base=31;
ll POW[200005];
ll n, m;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

struct node 
{
    ll idx;
    vector<ll> hash;
    string s;

    node(){}
    node(string _s, ll id)
    {
        s=_s;
        idx=id;
        ll n=s.size();
        hash.resize(n+1);
        hash[0]=0;
        for (ll i=1; i<=n; i++) hash[i]=(hash[i-1]*base+s[i-1]-'a'+1)%MOD;
    } 

    ll gethash(int i,int j) 
    {
        return (hash[j] - hash[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
    }
};
vector<node> v;

bool comp(node a, node b)
{
    if (a.hash.size()==b.hash.size() && a.hash.back()==b.hash.back()) return a.idx<b.idx;
    ll l=1, r=min(a.s.size(), b.s.size()), ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (a.gethash(1, mid)!=b.gethash(1, mid)) r=mid-1;
        else l=mid+1, ans=mid; 
    }        
    return a.s[ans]<b.s[ans];
}

ordered_set seg[800005];

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        seg[id].insert(v[l-1].idx);
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id]=seg[id*2];
    for (auto it: seg[id*2+1]) seg[id].insert(it);
}

// void update (ll id, ll l, ll r, ll u, ll v,ll oldval, ll newval)
// {
//     if(l>v || r<u) return;
//     if(l==r)
//     {    
//         seg[id].erase(oldval);
//         seg[id].insert(newval);
//         return;
//     }
//      ll mid = (l+r)/2;
//      update(id*2, l, mid, u, v, oldval, newval);
//      update(id*2+1, mid+1, r, u, v, oldval, newval);
//      seg[id] = max(seg[id*2], seg[id*2+1]);
// }

ll get(ll id, ll l, ll r , ll u, ll v, ll x, ll y)
{
    if(l>v || r<u) return 0;
    if(u<=l && r<=v) 
    {
        
        return seg[id].order_of_key(*seg[id].upper_bound(y))-seg[id].order_of_key(*seg[id].lower_bound(x))+1;
    }
     ll mid = (l+r)/2;
     return max(get(id*2,l,mid,u,v, x, y), get(id*2+1,mid+1,r,u,v, x, y));
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        v.push_back(node(s+" ", i+1));
    }
    sort(v.begin(), v.end(), comp);
    build(1, 1, n);
    for (ll i=0; i<n; i++) cout<<v[i].s<<" "<<v[i].idx<<" "<<endl;
    while (m--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll x, y; cin>>x>>y;
        }
        else 
        {
            string s; cin>>s;
            ll k, x, y; cin>>k>>x>>y;
            node tam=node(s.substr(0, k)+char(' '), 0);   cout<<tam.s<<"  ";
            ll l=0, r=n-1, upper=9;
            while (l<=r)
            {
                ll mid=(l+r)/2;
                if (comp(tam, v[mid])==true) upper=mid, l=mid+1;
                else r=mid-1;
            }
            cout<<upper<<endl;
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