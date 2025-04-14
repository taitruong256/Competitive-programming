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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, a[300005], minprime[300005], s, t, pos;
map<pair<ll, ll>, vector<pair<ll, ll>>> adj;
map<ll, ll> idx;
queue<pair<ll, ll>> q;
map<pair<ll, ll>, pair<ll, ll>> trace;
map<pair<ll, ll>, ll> dist;

void sieve()
{
    for (ll i=2; i*i<=300000; i++)
        for (ll j=i*i; j<=300000; j+=i) if (minprime[j]==0)
            minprime[j]=i;
    for (ll i=1; i<=300000; i++) if (minprime[i]==0) minprime[i]=i;
}

void solve()
{
    sieve();
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>s>>t;    

    for (ll i=1; i<=n; i++)
    {
        vector<ll> v;
        ll x=a[i]; 
        while (x>1)
        {
            ll t=minprime[x];
            if (idx.find(t)==idx.end()) idx[t]=++pos;
            x/=t;
            v.push_back(t);
            while (x>1 && x%t==0) x/=t;
        }

        for (auto x: v)
        {
            adj[{a[i], i}].push_back({x, idx[x]+300000});
            adj[{x, idx[x]+300000}].push_back({a[i], i});
        }
    }

    q.push({a[s], s});
    dist[{a[s], s}]=0;
    while (!q.empty())
    {
        auto [val, pos]=q.front(); q.pop();
        if (pos==t) break;
        for (auto [new_val, new_pos]: adj[{val, pos}])
        {
            if (dist.find({new_val, new_pos})==dist.end())
            {
                q.push({new_val, new_pos});
                dist[{new_val, new_pos}]=dist[{val, pos}]+1;
                trace[{new_val, new_pos}]={val, pos};
            }
        }
    }
    if (dist.find({a[t], t})==dist.end())
    {
        cout<<-1;
        return;
    }
    pair<ll, ll> fi={a[t], t};
    vector<ll> path;
    while (fi!=make_pair(a[s], s))
    {
        if (fi.second<=300000) path.push_back(fi.second);
        fi=trace[fi];
    }
    path.push_back(s);
    cout<<path.size()<<endl;
    reverse(path.begin(), path.end());
    for (auto i: path) cout<<i<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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