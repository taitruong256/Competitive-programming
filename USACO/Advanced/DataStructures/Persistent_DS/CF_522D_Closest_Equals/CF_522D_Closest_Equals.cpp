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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct node
{
    ll left, right, value;
    node(){}
    node(ll _l, ll _r, ll _value){left=_l, right=_r, value=_value;}
};
struct persistent_segment_tree
{
    ll nVer, nNode, n, cur;
    vector<ll> root;
    vector<node> tree;
    persistent_segment_tree(){}
    persistent_segment_tree(ll _n)
    {
        nVer=0;
        nNode=0;
        n=_n;
        root.push_back(1);
        tree.resize(23*n+20);
        build(1, n);
    }
    void pull(ll cur)
    {
        tree[cur].value=min(tree[tree[cur].left].value, tree[tree[cur].right].value);
    }
    ll build(ll l, ll r)
    {           
        if (l==r) 
        {
            ++nNode;
            tree[nNode]=node(l, r, mod);
            return nNode;
        }
        ll mid=(l+r)/2;
        ll cur=++nNode;
        tree[cur].left=build(l, mid);
        tree[cur].right=build(mid+1, r);
        pull(cur);
        return cur;
    }
    ll update(ll l, ll r, ll pos, ll val, ll old)
    {                    
        if (l==r)
        {
            ++nNode;
            tree[nNode]=node(l, r, val);
            return nNode;
        }
        ll mid=(l+r)/2;
        ll cur=++nNode;
        if (pos<=mid)
        {
            tree[cur].left=update(l, mid, pos, val, tree[old].left);
            tree[cur].right=tree[old].right;
            pull(cur);
        }
        else 
        {
            tree[cur].left=tree[old].left;
            tree[cur].right=update(mid+1, r, pos, val, tree[old].right);
            pull(cur);
        }
        return cur;
    }   
    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return mod;
        if (u<=l && r<=v) return tree[id].value;
        ll mid=(l+r)/2;
        return min(query(tree[id].left, l, mid, u, v), query(tree[id].right, mid+1, r, u, v));
    }
    void update_ver(ll ver, ll pos, ll val)
    {
        ll cur=nNode+1;
        update(1, n, pos, val, root[ver]);
        root[ver]=cur;
    }
    ll query_ver(ll ver, ll l, ll r)
    {
        return query(root[ver], 1, n, l, r);
    }
    void create_root(ll ver)
    {
        ++nVer;
        root.push_back(root[ver]);
    }
};

ll n, m, a[500005];
map<ll, ll> lst;

void solve()
{
    cin>>n>>m;
    persistent_segment_tree seg(n);
    
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        seg.create_root(i-1);  
        if (lst.find(a[i])!=lst.end()) seg.update_ver(i, lst[a[i]], i-lst[a[i]]);
        lst[a[i]]=i;
    }

    while (m--)
    {
        ll l, r; cin>>l>>r;
        ll ans=seg.query_ver(r, l, r);
        if (ans==mod) ans=-1;
        cout<<ans<<endl;
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