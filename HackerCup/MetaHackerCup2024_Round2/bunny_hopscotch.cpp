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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;
const ll maxn = 805;
ll bit[810][810];

void init()
{
    for (ll i=0; i<=800; i++)
        for (ll j=0; j<=800; j++)
            bit[i][j]=0;
}
void update(ll x, ll y, ll val)
{
    for (ll i=x; i<=800; i+=-i&i) 
        for (ll j=y; j<=800; j+=-j&j)
            bit[i][j]+=val;
}
ll query(ll x, ll y)
{
    ll ans=0;
    for (ll i=x; i>0; i-=-i&i)
        for (ll j=y; j>0; j-=-j&j)
            ans+=bit[i][j];
    return ans;
}
ll query2(ll x1, ll y1, ll x2, ll y2)
{
    ll ans=0;
    ans+=query(x2, y2);
    ans-=query(x1-1, y2);
    ans-=query(x2, y1-1);
    ans+=query(x1-1, y1-1);
    return ans;
}

ll n, m, k;
vector<pair<ll, ll>> pos[805*805];

void solve(ll testcase)
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            ll x; cin>>x;
            pos[x].push_back({i, j});
        }
    ll l=1, r=800, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        ll res=0;
        init();
        for (ll i=1; i<=n*m; i++)
        {
            if (pos[i].empty()) continue;

            for (auto [x, y]: pos[i])
            {
                ll x1=max(1LL, x-mid), y1=max(1LL, y-mid);
                ll x2=min(x+mid, n), y2=min(y+mid, m);
                res+=query2(x1, y1, x2, y2)*2;
            }

            for (auto [x, y]: pos[i]) update(x, y, 1);
        }

        if (res>=k) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<"Case #"<<testcase<<": "<<ans<<endl;
    for (ll i=1; i<=n*m; i++) pos[i].clear();
}   

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("bunny_hopscotch_input.txt", "r", stdin);
    freopen("bunny_hopscotch_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    for (ll i=1; i<=t; i++) solve(i);
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}