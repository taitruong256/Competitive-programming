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
const ll inf = 1e18;
const ll maxn=500005;

struct line{
    ll a, b;
    line()
    {
        a=0;
        b=-inf;
    }
    line(ll _a, ll _b)
    {
        a=_a;
        b=_b;
    }
};

struct interval_tree
{
    vector<line> tree;
    ll n;

    interval_tree(){}
    interval_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        buildtree(1, 1, n);
    }

    void buildtree(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=line(0, -inf);
            return;
        }
        ll mid=(l+r)/2;
        buildtree(id*2, l, mid);
        buildtree(id*2+1, mid+1, r);
        tree[id]=line(0, -inf);
    }

    ll get(line l, ll x)
    {
        return l.a*x+l.b;
    }

    ll query(ll id, ll l, ll r, ll pos)
    {               
        if (r<pos || l>pos) return -inf;
        if (l==pos && pos==r) return get(tree[id], pos);
        ll mid=(l+r)/2;
        return max({query(id*2, l, mid, pos), query(id*2+1, mid+1, r, pos), get(tree[id], pos)});
    }

    void update(ll id, ll l, ll r, line val)
    {
        if (l==r)
        {
            if (query(1, 1, n, l)>=get(val, l)) tree[id]=val;
            return;
        }
        ll mid=(l+r)/2;
        if (query(1, 1, n, l)>=get(val, l) && query(1, 1, n, r)>=get(val, r)) 
        {
            return;
        }
        else if (query(1, 1, n, l)<=get(val, l) && query(1, 1, n, r)<=get(val, r))
        {
            tree[id]=val;
            return;
        }
        else if (query(1, 1, n, l)>=get(val, l) && query(1, 1, n, mid)>=get(val, mid))
        {
            update(id*2+1, mid+1, r, val);
            return;
        }
        else if (query(1, 1, n, l)<=get(val, l) && query(1, 1, n, mid)<=get(val, mid))
        {
            update(id*2+1, mid+1, r, val);
            tree[id*2]=val;
            return;
        }
        else if (get(tree[id], mid+1)>=get(val, mid+1) && query(1, 1, n, r)>=get(val, r))
        {
            update(id*2, l, mid, val);
            return;
        }
        else 
        {
            update(id*2, l, mid, val);
            tree[id*2+1]=val;
            return;
        }
        return;
      
        update(id*2, l, mid, val);
        update(id*2+1, mid+1, r, val);
    }
};

void solve()
{
    interval_tree it = interval_tree(10);
    ll n=16;
    it.update(1, 1, n, line(1, 1));
    cout<<it.query(1, 1, n, 1)<<endl;
    cout<<it.query(1, 1, n, n)<<endl;
    for (ll i=1; i<26; i++) cout<<it.tree[i].a<<" "<<it.tree[i].b<<endl; cout<<endl;
    it.update(1, 1, n, line(0, 7));
    cout<<it.query(1, 1, n, 1)<<endl;
    cout<<it.query(1, 1, n, n)<<endl;
    for (ll i=1; i<26; i++) cout<<it.tree[i].a<<" "<<it.tree[i].b<<endl; cout<<endl;
    it.update(1, 1, n, line(-1, 11));
    for (ll i=1; i<26; i++) cout<<it.tree[i].a<<" "<<it.tree[i].b<<endl; cout<<endl;
    // cout<<it.query(1, 1, n, 1)<<endl;
    // cout<<it.query(1, 1, n, 2)<<endl;
    // cout<<it.query(1, 1, n, 3)<<endl;
    // cout<<it.query(1, 1, n, 4)<<endl;
    // cout<<it.query(1, 1, n, 5)<<endl;
    // cout<<it.query(1, 1, n, 6)<<endl;
    // cout<<it.query(1, 1, n, 7)<<endl;
    // cout<<it.query(1, 1, n, 8)<<endl;
    // cout<<it.query(1, 1, n, 9)<<endl;
    // cout<<it.query(1, 1, n, 10)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}