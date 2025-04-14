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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

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

ll n, a[100005], l[100005], r[100005];

void solve()
{
    setIO("bphoto");
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    set<ll> st;
    for (ll i=1; i<=n; i++) st.insert(a[i]);
    vector<ll> v;
    for (auto i: st) v.push_back(i);
    fenwick ft(n);
    for (ll i=1; i<=n; i++)
    {
        ll pos=lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
        l[i]=ft.getsum(pos+1, n);
        ft.update(pos, 1);
    }
    ft=fenwick(n);
    for (ll i=n; i>=1; i--)
    {
        ll pos=lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
        r[i]=ft.getsum(pos+1, n);
        ft.update(pos, 1);
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) if (max(l[i], r[i])>2*min(l[i], r[i])) ++ans;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}