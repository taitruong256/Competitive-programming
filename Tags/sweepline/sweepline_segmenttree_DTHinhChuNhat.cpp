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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxn=30000;
struct node
{
    ll cnt, cover;
    node(){}
    node(ll _cnt, ll _cover)
    {
        cnt=_cnt;
        cover=_cover;
    }
};

struct qry
{
    ll x, y1, y2, type;
    qry(){}
    qry(ll _x, ll _y1, ll _y2, ll _type)
    {
        x=_x;
        y1=_y1;
        y2=_y2;
        type=_type;
    }

    bool operator < (qry other)
    {
        if (x==other.x) return type<other.type;
        return x<other.x;
    }
};

struct segment_tree
{
    ll n;
    vector<node> tree;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, node(0LL, 0LL));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            tree[id].cnt+=val;
            if (tree[id].cnt!=0) tree[id].cover=r-l+1;
            else if (l!=r) tree[id].cover=tree[id*2].cover+tree[id*2+1].cover;
            else tree[id].cover=0;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        if (tree[id].cnt!=0) tree[id].cover=r-l+1;
        else tree[id].cover=tree[id*2].cover+tree[id*2+1].cover;
    }
};

void solve()
{
    ll n; cin>>n;
    vector<qry> query;
    for (ll i=0; i<n; i++) 
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        if (x1>x2) swap(x1, x2);
        if (y1>y2) swap(y1, y2);
        query.push_back(qry(x1, y1, y2, 1));
        query.push_back(qry(x2, y1, y2, -1));
    }
    sort(query.begin(), query.end());
    ll ans=0;
    segment_tree st=segment_tree(maxn);
    for (ll i=0; i<query.size()-1; i++)
    {
        st.update(1, 0, maxn, query[i].y1, query[i].y2-1, query[i].type);  
        ans+=st.tree[1].cover*(query[i+1].x-query[i].x);
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