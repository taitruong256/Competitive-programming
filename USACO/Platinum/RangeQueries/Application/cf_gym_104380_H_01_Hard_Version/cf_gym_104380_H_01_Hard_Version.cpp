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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
string s;
ll n, q;

struct segment_tree 
{
    struct node {ll open, close, ans; };
    ll n;
    vector<node> tree;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    node merge(node a, node b)
    {
        ll opt=min(a.open, b.close);
        node new_node;
        new_node.open=a.open+b.open-opt;
        new_node.close=a.close+b.close-opt;
        new_node.ans=a.ans+b.ans+opt;
        return new_node;
    }

    node convert(ll x)
    {
        if (x==0) return {1, 0, 0}; //open
        if (x==1) return {0, 1, 0}; //close
        return {0, 0, 0};
    }

    void update(ll id, ll l, ll r, ll pos)
    {
        if (l==pos && pos==r)
        {
            tree[id]=convert(s[pos]-'0');
            return;
        }
        ll mid=(l+r)/2;
        if (pos<=mid) update(id*2, l, mid, pos);
        else update(id*2+1, mid+1, r, pos);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }

    node query(ll id, ll l, ll r, ll u, ll v)
    {
        if (r<u || l>v) return convert(2);
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return merge(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void debugs(ll id, ll l, ll r)
    {
        if (l==r)
        {
            cout<<l<<" "<<tree[id].open<<" "<<tree[id].close<<endl;
            return;
        }
        ll mid=(l+r)/2;
        debugs(id*2, l, mid);
        debugs(id*2+1, mid+1, r);
    }
};

void solve()
{
    cin>>s; n=s.size(); s=" "+s;
    segment_tree seg(n);
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, i);
    cin>>q;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1) 
        {
            ll pos; cin>>pos;
            ll val=s[pos]-'0';
            s[pos]=char('0'+1-val);   
            seg.update(1, 1, n, pos);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<(r-l+1)-2*seg.query(1, 1, n, l, r).ans<<endl;
        }
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