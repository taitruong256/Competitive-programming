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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll maxx = 1e6+5;

struct segment_tree
{
    vector<pair<ll, ll>> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id].first+=val;
            if (tree[id].first>0) tree[id].second=(r-l+1);
            else if (l!=r) tree[id].second=tree[id*2].second+tree[id*2+1].second;
            else tree[id].second=0;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        if (tree[id].first>0) tree[id].second=(r-l+1);
        else tree[id].second=tree[id*2].second+tree[id*2+1].second;
    }
};

struct query
{
    ll type, x, y1, y2;

    bool operator < (query other)
    {
        return x<other.x;
    }
};

void solve()
{
    ll n; cin>>n;
    segment_tree st(2*maxx);
    vector<query> qry;
    for (ll i=1; i<=n; i++)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        y1+=maxx;
        y2+=maxx;
        qry.push_back({1, x1, y1, y2});
        qry.push_back({-1, x2, y1, y2});
    }
    ll ans=0;
    sort(qry.begin(), qry.end());
    for (ll i=0; i<qry.size()-1; i++)
    {
        st.update(1, 0, 2*maxx, qry[i].y1, qry[i].y2-1, qry[i].type);
        ans+=st.tree[1].second*(qry[i+1].x-qry[i].x);
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