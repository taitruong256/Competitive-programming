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
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll maxn=262144;
ll a[maxn];

struct segment_tree
{
    ll n, ans;
    bool check;
    vector<ll> tree, height;
    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        ans=0;
        check=true;
        tree.resize(4*n+5);
        height.resize(4*n+5);
        build(1, 1, n);
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r) 
        {
            tree[id]=a[l];
            height[id]=1;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=max(tree[id*2], tree[id*2+1]);
        height[id]=height[id*2]*2;
    }

    void query(ll id, ll l, ll r)
    {
        if (l==r) return;
        ll mid=(l+r)/2;
        if (abs(tree[id*2]-tree[id*2+1])!=height[id]/2) check=false;
        if (tree[id*2]>tree[id*2+1]) ++ans;
        query(id*2, l, mid);
        query(id*2+1, mid+1, r);
    }
};

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree seg(n);
    seg.query(1, 1, n);
    if (seg.check==false) cout<<-1<<endl;
    else cout<<seg.ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}