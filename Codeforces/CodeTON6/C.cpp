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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll query_first(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) 
        {
            if (tree[id]<val) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2]>=val) id=id*2, r=mid;
                else id=id*2+1, l=mid+1; 
            }
            return l;
        }
        ll mid=(l+r)/2;
        ll left=query_first(id*2, l, mid, u, v, val);
        ll right=query_first(id*2+1, mid+1, r, u, v, val);
        if (left!=-1) return left;
        return right;
    }

    ll query_last(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) 
        {
            if (tree[id]<val) return -1;
            while (l!=r)
            {
                ll mid=(l+r)/2;
                if (tree[id*2+1]>=val) id=id*2+1, l=mid+1;
                else id=id*2, r=mid; 
            }
            return l;
        }
        ll mid=(l+r)/2;
        ll left=query_last(id*2, l, mid, u, v, val);
        ll right=query_last(id*2+1, mid+1, r, u, v, val);
        if (right!=-1) return right;
        return left;
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

void solve()
{
    ll n, k, mn=1e18, mx=-1e18; cin>>n>>k;
    ll a[n+5];
    segment_tree seg(n);
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        mn=min(mn, a[i]);
        mx=max(mx, a[i]);
        seg.update(1, 1, n, i, a[i]);
    }

    for (ll i=1; i<=k; i++) 
    {
        if (i<mn || i>mx) cout<<0<<" ";
        else cout<<2*(seg.query_last(1, 1, n, 1, n, i)-seg.query_first(1, 1, n, 1, n, i)+1)<<" ";
    }
    cout<<endl;
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