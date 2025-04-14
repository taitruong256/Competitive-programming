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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct segment_tree_max
{
    vector<ll> tree;
    ll n;

    segment_tree_max(){}
    segment_tree_max(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v, ll k)  
    {
        if (l>v || r<u) return -1;
        if (u<=l && r<=v) 
        {
            if (tree[id]<k) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2]>=tree[id*2+1]) r=mid, id=id*2;
                else l=mid+1, id=id*2+1;
            }
            return l;
        }
        ll mid=(l+r)/2;
        ll left=query(id*2, l, mid, u, v, k);
        if (left!=-1) return left;
        return query(id*2+1, mid+1, r, u, v, k);
    }

    ll value(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return -1;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(value(id*2, l, mid, u, v), value(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

struct segment_tree_sum
{
    vector<ll> tree;
    ll n;

    segment_tree_sum(){}
    segment_tree_sum(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

ll n, k, a[100005];
segment_tree_max segmax(100000);
segment_tree_sum segcnt(100000);

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) segmax.update(1, 1, n, i, a[i]);
    vector<ll> ans;
    for (ll i=1; i<=n; i++)
    {
        ll l=1, r=min(1+k+segcnt.query(1, 1, n, 1, min(n, 1+k)), n); cout<<l<<" "<<r<<"   ";
        ll val=segmax.value(1, 1, n, l, r);  
        ll pos=segmax.query(1, 1, n, l, r, val);   cout<<pos<<" "<<val<<"   ";
        ans.push_back(val);
        segcnt.update(1, 1, n, pos, 1);
        segmax.update(1, 1, n, pos, -1);
        ll cnt=pos-segcnt.query(1, 1, n, 1, pos);
        k-=cnt;
        for (ll j=1; j<=n; j++) cout<<segmax.value(1, 1, n, j, j)<<" "; cout<<"    "<<k<<endl;
    }
    for (auto i: ans) cout<<i<<" ";
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