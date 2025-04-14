#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[200005], d[200005];

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    ll opt(ll x, ll y)
    {
        return min(x, y);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=a[l]; 
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }

    ll query_index(ll id, ll l, ll r, ll u, ll v, ll x)  //tim chi index dau tien <x trong doan [u, v]
    {
        if (l>v || r<u || l>r) return -1;
        if (u<=l && r<=v) 
        {
            if (tree[id]>=x) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2]<x) id=id*2, r=mid;
                else id=id*2+1, l=mid+1;
            }
            return l;
        }
        ll mid=(l+r)/2;
        ll left=query_index(id*2, l, mid, u, v, x);
        ll right=query_index(id*2+1, mid+1, r, u, v, x);
        if (left!=-1) return left;
        return right;
    }

    ll query_min(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e18;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query_min(id*2, l, mid, u, v), query_min(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]+=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

bool check(ll x)
{
    segment_tree seg(n);
    for (ll i=1; i<=n; i++)
    {
        ll val=seg.query_min(1, 1, n, i, i);
        while (val>x)  
        {
            ll l=max(1LL, i-d[i]), r=min(n, i+d[i]), k=seg.query_index(1, 1, n, l, r, x);
            if (k==-1) return false;
            ll cnt=min(val-x, x-seg.query_min(1, 1, n, k, k));
            seg.update(1, 1, n, k, cnt);
            seg.update(1, 1, n, i, -cnt);
            val=seg.query_min(1, 1, n, i, i);
            // for (ll j=1; j<=n; j++) cout<<seg.query_min(1, 1, n, j, j)<<" "; cout<<endl;
        }
        while (true)
        {
            ll l=max(1LL, i-d[i]), r=i-1, k=seg.query_index(1, 1, n, l, r, x);
            if (k==-1) break;
            val=seg.query_min(1, 1, n, i, i);
            if (val==0) break;
            ll cnt=min(val, x-seg.query_min(1, 1, n, k, k));     
            seg.update(1, 1, n, k, cnt);
            seg.update(1, 1, n, i, -cnt);
            // for (ll j=1; j<=n; j++) cout<<seg.query_min(1, 1, n, j, j)<<" "; cout<<endl;
        }
    }
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>d[i];

    ll l=0, r=1e10, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
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