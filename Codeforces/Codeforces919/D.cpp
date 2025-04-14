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

void solve()
{
    ll n, q; cin>>n>>q;
    vector<pair<ll, ll>> len;
    len.push_back({0, -1});
    ll cur=0;
    map<ll, ll> ins;
    for (ll i=1; i<=n; i++)
    {
        ll type, x; cin>>type>>x;
        if (type==1) ++cur, len.push_back({cur, -1}), ins[cur]=x;
        else cur*=(x+1), len.push_back({cur, x+1});
    }
    map<ll, vector<ll>> qry;
    qry[0].push_back(0);
    for (ll i=1; i<=q; i++)
    {
        ll k; cin>>k;
        qry[k].push_back(i);
    }
    auto it=qry.rbegin();
    ll ans[q+5];
    while (true)
    {
        auto [x, y]=*it;
        auto [u, v]=len.back(); 
        len.pop_back();
        if (x==-1) break;
        if (ins.find(u)!=ins.end())
        {
            for (auto i: y) ans[i]=ins[u];
            it=prev(it);
            continue;
        }
        if (x>=u) 
        {
            if (len.back().first!=-1) 
            {
                for (auto i: y) qry[x/v].push_back(i);
            }
            else 
            {
                for (auto i: y) qry[x-1].push_back(i);
            }
            it=prev(it);
            continue;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}