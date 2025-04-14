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
ll n, q, a[200005];

struct node
{
    ll left, right, value;
    node(){}
    node(ll _l, ll _r, ll _value){left=_l, right=_r, value=_value;}
};
struct persistent_segment_tree
{
    ll nVer, nNode, n, cur;
    vector<ll> version;
    vector<node> tree;
    persistent_segment_tree(){}
    persistent_segment_tree(ll _n)
    {
        nVer=0;
        nNode=0;
        n=_n;
        tree.resize(25*n*20);
        version.resize(1);
        build(1, n);
        version[nVer]=1;
    }
    void pull(ll cur)
    {
        tree[cur].value=tree[tree[cur].left].value+tree[tree[cur].right].value;
    }
    ll build(ll l, ll r)
    {           
        if (l==r) 
        {
            ++nNode;
            tree[nNode]=node(l, r, 0);
            return nNode;
        }
        ll mid=(l+r)/2;
        ll cur=++nNode;
        tree[cur].left=build(l, mid);
        tree[cur].right=build(mid+1, r);
        pull(cur);
        return cur;
    }
    ll update(ll l, ll r, ll pos, ll val, ll old, ll add)
    {                    
        if (l==r)
        {
            ++nNode;
            tree[nNode]=node(l, r, val+add);
            return nNode;
        }
        ll mid=(l+r)/2;
        ll cur=++nNode;
        if (pos<=mid)
        {
            tree[cur].left=update(l, mid, pos, val, tree[old].left, add);
            tree[cur].right=tree[old].right;
            pull(cur);
        }
        else 
        {
            tree[cur].left=tree[old].left;
            tree[cur].right=update(mid+1, r, pos, val, tree[old].right, add);
            pull(cur);
        }
        return cur;
    }   
    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].value;
        ll mid=(l+r)/2;
        return query(tree[id].left, l, mid, u, v)+query(tree[id].right, mid+1, r, u, v);
    }
    void update_ver(ll ver, ll pos, ll val)
    {
        ll cur=nNode+1;
        ll add=query(version[ver], 1, n, pos, pos);
        update(1, n, pos, val, version[ver-1], add);
        version[ver]=cur;
    }
    ll query_ver(ll ver, ll l, ll r)
    {
        return query(version[ver], 1, n, l, r);
    }
    void create_version(ll ver)
    {
        ++nVer;
        version.push_back(version[ver]);
    }
};

void solve()
{
    cin>>n>>q;
    persistent_segment_tree seg(200000);
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        seg.create_version(i-1);
        seg.update_ver(i, a[i], 1);
    }
 
    while (q--)
    {
        ll l, r; cin>>l>>r;
        ll low=1, high=r-l+1, ans=1;
        while (low<=high)
        {
            ll mid=(low+high)/2;
            ll cnt=seg.query_ver(r, mid, 200000)-seg.query_ver(l-1, mid, 200000);
            if (cnt>=mid) ans=mid, low=mid+1;
            else high=mid-1;
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}