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
 
    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};
ll n, q, a[200005], ans[200005], pref[200005], contrib[200005];
vector<pair<ll, ll>> query[200005];
 
void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    a[n+1]=1e18;
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    pref[n+1]=pref[n]+a[n+1];
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        query[l].push_back({r, i});
    }
 
    deque<ll> stk;
    fenwick ft(200002);
    stk.push_back(n+1);
    for (ll l=n; l>=1; l--)
    {
        while (!stk.empty() && a[l]>=a[stk.front()]) 
        {
            ft.update(stk.front(), -contrib[stk.front()]);
            stk.pop_front();
        }
        contrib[l]=(stk.front()-1-l)*a[l]-(pref[stk.front()-1]-pref[l]);
        ft.update(l, contrib[l]);
        stk.push_front(l);
        for (auto [r, i]: query[l])
        {
            ll pos=upper_bound(stk.begin(), stk.end(), r)-stk.begin()-1;
            ans[i] = (pos ? ft.query(l, stk[pos - 1]) : 0) + (r - stk[pos]) * a[stk[pos]] - (pref[r] - pref[stk[pos]]);
        }
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
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