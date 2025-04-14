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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
 
struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;
 
    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, 0);
        lazy.resize(4*n+5, 0);
    }
 
    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id];
        if (t>0 && l!=r)
        {
            ll mid=(l+r)/2;
            tree[id*2]=mid-l+1;
            lazy[id*2]=1;
            tree[id*2+1]=r-mid;
            lazy[id*2+1]=1;
        }
        lazy[id]=0;
    }
 
    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return -1;
        if (u<=l && r<=v) 
        {
            if (tree[id]==r-l+1) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2]<mid-l+1) id=id*2, r=mid;
                else id=id*2+1, l=mid+1;
            }
            return l;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        ll le=query(id*2, l, mid, u, v);
        if (le!=-1) return le;
        return query(id*2+1, mid+1, r, u, v);
    }
 
    ll query_sum(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return query_sum(id*2, l, mid, u, v)+query_sum(id*2+1, mid+1, r, u, v);
    }
 
    void update(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]=r-l+1;
            lazy[id]=1;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};
 
vector<ll> comp, qry;
ll getid(ll val)
{
    return lower_bound(comp.begin(), comp.end(), val)-comp.begin()+1;
}
 
ll getval(ll id)
{
    return comp[id-1];
}
 
void solve()
{
    ll n; cin>>n;
    pair<ll, ll> sm[n+5];
    
    for (ll i=1; i<=n; i++)
    {
        ll l, r, a, b; cin>>l>>r>>a>>b;
        sm[i]={l, b};
        comp.push_back(l);
        comp.push_back(b);
    }
 
    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll x; cin>>x;
        comp.push_back(x);
        qry.push_back(x);
    }
 
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end())-comp.begin());
 
    ll m=comp.size()+1;
    m*=2;
    segment_tree_lazy seg(m);
    for (ll i=1; i<=n; i++) seg.update(1, 1, m, getid(sm[i].first)*2, getid(sm[i].second)*2);
 
    for (ll i=1; i<=q; i++)
    {
        ll x=getid(qry[i-1]);
        ll s=seg.query_sum(1, 1, m, x*2, x*2);
        if (s==1) cout<<getval(seg.query(1, 1, m, x*2, m)/2)<<" ";
        else cout<<getval(x)<<" ";
    }
    cout<<endl;
    comp.clear();
    qry.clear();
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}