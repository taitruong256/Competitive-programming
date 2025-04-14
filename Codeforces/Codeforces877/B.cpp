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

    ll getsum(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};
ll n, a[200005], b[200005], pos[200005];

ll phuongan(vector<ll> v)
{
    ll ans=0, mx=0;
    if (v.back()==1) reverse(v.begin(), v.end());
    fenwick ft(n);
    for (auto i: v) 
    {
        mx=max(mx, i);
        ft.update(i, 1);
        if (ft.query(mx)==mx) ++ans;
    }
    return ans;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i], pos[a[i]]=i;
    vector<ll> v;
    ll x1, x2, x3, x4;


    v.clear();
    for (ll i=1; i<=n; i++) b[i]=a[i];
    swap(b[pos[1]], b[1]);
    for (ll i=1; i<=n; i++) v.push_back(b[i]);
    x1=phuongan(v);
    for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl; cout<<x1<<endl;


    v.clear();
    for (ll i=1; i<=n; i++) b[i]=a[i];
    swap(b[pos[1]], b[n]);
    for (ll i=1; i<=n; i++) v.push_back(b[i]);
    x2=phuongan(v);
    for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl; cout<<x2<<endl;


    v.clear();
    for (ll i=1; i<=n; i++) b[i]=a[i];
    swap(b[pos[2]], b[1]);
    for (ll i=1; i<=n; i++) v.push_back(b[i]);
    x3=phuongan(v);
    for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl; cout<<x3<<endl;


    v.clear();
    for (ll i=1; i<=n; i++) b[i]=a[i];
    swap(b[pos[2]], b[n]);
    for (ll i=1; i<=n; i++) v.push_back(b[i]);
    x4=phuongan(v);
    for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl; cout<<x4<<endl;


    ll mn=min({x1, x2, x3, x4});
    if (x1==mn) cout<<pos[1]<<" "<<1<<endl;
    else if (x2==mn) cout<<pos[1]<<" "<<n<<endl;
    else if (x3==mn) cout<<pos[2]<<" "<<1<<endl;
    else if (x4==mn) cout<<pos[2]<<" "<<n<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}