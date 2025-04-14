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

struct Mo
{
    ll l, r, id, block_size;
    Mo(){}
    Mo(ll _l, ll _r, ll _id, ll _n)
    {
        l=_l;
        r=_r;
        id=_id;
        block_size=ceil(sqrt(_n));
    }
    bool operator< (Mo other)
    {
        if (l/block_size!=other.l/block_size) return l/block_size<other.l/block_size;
        if (l/block_size%2==1) return r<other.r;
        return r>other.r;
    }
};

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};

ll n, q, a[100005], result[100005];
vector<Mo> v; 
vector<ll> comp;

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        comp.push_back(a[i]);
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end())-comp.begin());
    for (ll i=1; i<=n; i++) a[i]=lower_bound(comp.begin(), comp.end(), a[i])-comp.begin()+1;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r; ++l;
        v.push_back(Mo(l, r, i, n));
    }
    sort(v.begin(), v.end());
    ll l=1, r=0, ans=0;
    fenwick ft(n);
    for (auto [lx, rx, id, zz]: v)
    {
        while (l<lx)
        {
            ans-=ft.query(1, a[l]-1);
            ft.update(a[l], -1);
            ++l;
        }
        while (l>lx)
        {
            --l;
            ft.update(a[l], 1);
            ans+=ft.query(1, a[l]-1);
        }
        while (r<rx)
        {
            ++r;
            ft.update(a[r], 1);
            ans+=ft.query(a[r]+1, n);
        }
        while (r>rx)
        {
            ans-=ft.query(a[r]+1, n);
            ft.update(a[r], -1);
            --r;
        }
        result[id]=ans;   
    }
    for (ll i=1; i<=q; i++) cout<<result[i]<<endl;
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