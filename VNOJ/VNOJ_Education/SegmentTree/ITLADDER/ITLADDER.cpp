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

struct segment_tree_lazy
{
    vector<ll> tree, lazy1, lazy2, lazy3;   
    //lazy1 tinh tong B
    //lazy2 tinh tong -a*l
    //lazy3 tinh tong l*a, (l+1)*a, ... r*a
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy1.resize(4*n+5);
        lazy2.resize(4*n+5);
        lazy3.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return (x+y)%mod;
    }

    ll f(ll l, ll r)
    {
        ll sl=(l-1)*l/2;
        ll sr=r*(r+1)/2;
        return sr-sl;
    }

    void down(ll id, ll l, ll r)
    {
        ll t, mid;
        // update b
        t=lazy1[id];
        mid=(l+r)/2;
        tree[id*2]=(tree[id*2]+t*(mid-l+1))%mod;
        lazy1[id*2]=(lazy1[id*2]+t)%mod;
        tree[id*2+1]=(tree[id*2+1]+t*(r-mid))%mod;
        lazy1[id*2+1]=(lazy1[id*2+1]+t)%mod;
        lazy1[id]=0;
        // update -l*a 
        t=lazy2[id];
        mid=(l+r)/2;
        tree[id*2]=(tree[id*2]+t*(mid-l+1))%mod;
        lazy2[id*2]=(lazy2[id*2]+t)%mod;
        tree[id*2+1]=(tree[id*2+1]+t*(r-mid))%mod;
        lazy2[id*2+1]=(lazy2[id*2+1]+t)%mod;
        lazy2[id]=0;
        // update l*a, (l+1)*a, ... r*a
        t=lazy3[id];
        mid=(l+r)/2;
        tree[id*2]=(tree[id*2]+t*f(l, mid))%mod;
        lazy3[id*2]=(lazy3[id*2]+t)%mod;
        tree[id*2+1]=(tree[id*2+1]+t*f(mid+1, r))%mod;
        lazy3[id*2+1]=(lazy3[id*2+1]+t)%mod;
        lazy3[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll a, ll b)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]=(tree[id]+f(l, r)*a-(r-l+1)*u*a+(r-l+1)*b+mod*mod)%mod;
            lazy1[id]=(lazy1[id]+b)%mod;
            lazy2[id]=(lazy2[id]-u*a+mod*mod)%mod;
            lazy3[id]=(lazy3[id]+a)%mod;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, a, b);
        update(id*2+1, mid+1, r, u, v, a, b);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    segment_tree_lazy seg(n);
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll l, r, a, b; cin>>l>>r>>a>>b;
            seg.update(1, 1, n, l, r, a, b);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query(1, 1, n, l, r)<<endl;
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