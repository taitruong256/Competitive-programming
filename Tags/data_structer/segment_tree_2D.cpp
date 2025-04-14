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
                              Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll int
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7, inf = 1e9;
ll n;

struct segment_2D
{
    ll n;
    vector<vector<ll>> tree;
    segment_2D() {}
    segment_2D(ll _n)
    {
            n=_n;
            tree.resize(4*n+5, vector<ll> (4*n+5));
            build(1, 1, n);
    }

    void build_row(ll id, ll l, ll r, ll row, ll idx, ll st, ll fi)
    {
        if (l==r)
        {
            if (st==fi) tree[row][id]=0;
            else tree[row][id]=tree[row*2][id]+tree[row*2+1][id];
            return;
        }
        ll mid=(l+r)/2;
        build_row(id*2, l, mid, row, idx, st, fi);
        build_row(id*2+1, mid+1, r, row, idx, st, fi);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            build_row(1, 1, n, id, l, l, r);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        build_row(1, 1, n, id, l, l, r);
    }

    void update_row(ll id, ll l, ll r, ll u, ll v, ll val, ll row, ll st, ll fi)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            tree[row][id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        if (u<=mid) update_row(id*2, l, mid, u, v, val, row, st, fi);
        else update_row(id*2+1, mid+1, r, u, v, val, row, st, fi);
        tree[row][id]=tree[row][id*2]+tree[row][id*2+1];
    }

    void update(ll id, ll l, ll r, ll x, ll y, ll val)
    {
        if (l>x || r<x) return;
        if (l==x && r==x)
        {
            update_row(1, 1, n, y, y, val, id, l, r);
            return;
        }
        ll mid=(l+r)/2;
        if (x<=mid) 
        {
            update(id*2, l, mid, x, y, val);
            update_row(1, 1, n, y, y, val, id, l, r);
        }
        else 
        {
            update(id*2+1, mid+1, r, x, y, val);
            update_row(1, 1, n, y, y, val, id, l, r);
        }
    }

    ll query_row(ll id, ll l, ll r, ll u, ll v, ll row)
    {
        if (l>v || r<u) return 0;
        if (l>=u && r<=v) return tree[row][id];
        ll mid=(l+r)/2;
        return query_row(id*2, l, mid, u, v, row)+query_row(id*2+1, mid+1, r, u, v, row);
    }

    ll query(ll id, ll l, ll r, ll x1, ll y1, ll x2, ll y2)
    {
        if (l>x2 || r<x1) return 0;
        if (x1<=l && r<=x2) return query_row(1, 1, n, y1, y2, id);
        ll mid=(l+r)/2;
        return query(id*2, l, mid, x1, y1, x2, y2)+query(id*2+1, mid+1, r, x1, y1, x2, y2);
    }
};

void solve()
{
    segment_2D st;
    while (1==1)
    {
        ll type; cin>>type; 
        if (type==0) 
        {
            cin>>n;
            st = segment_2D(n);
        }
        else if (type==1)
        {
            ll x, y, val; cin>>x>>y>>val;
            ++x; ++y;
            st.update(1, 1, n, x, y, val);
        }
        else if (type==2)
        {
            ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            ++x1; ++y1; ++x2; ++y2;    
            cout<<st.query(1, 1, n, x1, y1, x2, y2)<<endl;
        }
        else break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}