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

struct LiChao_tree       //offline + get min
{
    struct line 
    {
        ll a, b;
        ll get(ll x) {return a*x+b;}
    };
 
    ll n;
    vector<line> tree;
    vector<ll> compress;
 
    LiChao_tree(vector<ll> _compress_x)
    {
        n=_compress_x.size()+5;
        compress=_compress_x;
        sort(compress.begin(), compress.end());
        compress.resize(unique(compress.begin(), compress.end())-compress.begin());
        tree.resize(4*n+5, {0, LLONG_MAX});       //LLONG_MIN
    }

    ll getid(ll val) {return lower_bound(compress.begin(), compress.end(), val)-compress.begin();}
 
    void insert(ll id, ll l, ll r, line newL)
    {
        if (l==r)
        {
            if (newL.get(compress[l])<tree[id].get(compress[l])) tree[id]=newL;    //thay dau >
            return;
        }
        ll m=(l+r)/2;
        bool lef=newL.get(compress[l])<tree[id].get(compress[l]);    //thay dau >
        bool mid=newL.get(compress[m])<tree[id].get(compress[m]);    //thay dau >
        if (mid==true) swap(newL, tree[id]);
        if (lef!=mid) insert(id*2, l, m, newL);
        else insert(id*2+1, m+1, r, newL);
    }

    void insert(ll a, ll b)
    {
        line newL={a, b};
        insert(1, 0, n-1, newL);
    }
 
    ll query(ll id, ll l, ll r, ll x)
    {
        if (l==r) return tree[id].get(compress[x]);
        ll m=(l+r)/2;
        if (x<=m) return min(tree[id].get(compress[x]), query(id*2, l, m, x));   //max()
        return min(tree[id].get(compress[x]), query(id*2+1, m+1, r, x));   //max()
    }
 
    ll query(ll x)
    {
        ll pos=getid(x);
        return query(1, 0, n-1, pos);
    }
};

struct query
{
    ll type, a, b, x;
};
vector<query> qry;

void solve()
{
    ll n, q; cin>>n>>q;
    vector<ll> compress;
    for (ll i=1; i<=n; i++)
    {
        ll a, b; cin>>a>>b;
        qry.push_back({0, a, b, 0});
    }
    for (ll i=1; i<=q; i++)
    {
        ll type; cin>>type;
        ll a=0, b=0, x=0;
        if (type==0) cin>>a>>b;
        else cin>>x;
        qry.push_back({type, a, b, x});
        compress.push_back(x);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end())-compress.begin());
    LiChao_tree seg(compress);
    for (auto [type, a, b, x]: qry)
    {
        if (type==0) seg.insert(a, b);
        else cout<<seg.query(x)<<endl;
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