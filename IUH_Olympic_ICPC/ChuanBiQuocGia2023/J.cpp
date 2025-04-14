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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    void init(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) 
        {
            bit[i]+=val;
            bit[i]%=mod;
        }
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) 
        {
            sum+=bit[i];
            sum%=mod;
        }
        return sum;
    }

    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return (query(r)-query(l-1)+mod)%mod;
    }
};

ll dp[2005][2005];
fenwick ft[2005];
pair<ll, ll> a[2005];
vector<ll> qry[2005];

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

vector<ll> v;
ll id(ll n)
{
    return lower_bound(v.begin(), v.end(), n)-v.begin()+1;
}

void solve()
{
    ll n; cin>>n; 
    for (ll i=1; i<=n; i++) cin>>a[i].first;
    for (ll i=1; i<=n; i++) cin>>a[i].second;
    sort(a+1, a+n+1, comp);
    
    for (ll i=1; i<=n; i++) v.push_back(a[i].second);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for (ll i=1; i<=n; i++) a[i].second=id(a[i].second);
    v.clear();
    for (ll i=1; i<=n; i++) v.push_back(a[i].first);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for (ll i=1; i<=n; i++) a[i].first=id(a[i].first);

    for (ll i=1; i<=n; i++) qry[a[i].first].push_back(a[i].second);

    for (ll i=0; i<=n; i++) ft[i].init(n);
    for (ll i=n; i>=1; i--)
    {
        for (auto x: qry[i])
        {
            dp[x][1]+=1;
            dp[x][1]%=mod;
            ft[1].update(x, 1);
            for (ll j=2; j<=n; j++)
            {
                dp[x][j]+=ft[j-1].query(1, x-1);
                dp[x][j]%=mod;
                ft[j].update(x, ft[j-1].query(1, x-1));
            }
        }        
    }
    for (ll i=1; i<=n; i++) cout<<ft[i].query(n)<<" ";
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