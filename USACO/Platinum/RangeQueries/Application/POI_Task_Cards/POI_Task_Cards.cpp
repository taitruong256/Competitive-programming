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
#define ll int
#define endl '\n'
ll n, q;
pair<ll, ll> a[200005];

ll bit(ll x, ll i)
{
    if (x&(1<<i)) return 1;
    return 0;
}

struct node 
{
    ll l, r;
    bool state[4];
    node() {}
    node(ll _n)
    {
        l=r=_n;
        for (ll i=0; i<4; i++) state[i]=false;
        state[0]=1;
        state[3]=1;
    }
    pair<ll, ll> get_val(ll mask)
    {       
        ll left=bit(mask, 1)==0?a[l].first:a[l].second;
        ll right=bit(mask, 0)==0?a[r].first:a[r].second;
        return {left, right};
    }
};

node merge(node a, node b)
{
    node new_node;
    new_node.l=a.l;
    new_node.r=b.r;
    for (ll i=0; i<4; i++) new_node.state[i]=0;
    for (ll i=0; i<4; i++) 
        for (ll j=0; j<4; j++) 
        {
            ll mask=bit(i, 1)*2+bit(j, 0);
            if (a.state[i]==true && b.state[j]==true && a.get_val(i).second<=b.get_val(j).first)
                new_node.state[mask]=1;
        }
    return new_node;
}

node tree[800020];

struct segment_tree
{
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=node(l);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }

    void update(ll id, ll l, ll r, ll pos)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=node(pos);
            return;
        }
        ll mid=(l+r)/2;
        if (pos<=mid) update(id*2, l, mid, pos);
        else update(id*2+1, mid+1, r, pos);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n; 
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    segment_tree seg(n);
    cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        swap(a[l], a[r]);
        seg.update(1, 1, n, l);
        seg.update(1, 1, n, r);
        ll ans=0;
        for (ll i: tree[1].state) ans|=i;
        if (ans==1) cout<<"TAK\n";
        else cout<<"NIE\n";
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

