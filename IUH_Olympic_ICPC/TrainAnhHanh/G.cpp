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
#define ll int
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll maxn=1e7;
pair<ll, ll> pos[maxn+5];
ll n, a[1000005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        if (pos[a[i]].first==0) pos[a[i]].first=i;
        else if (pos[a[i]].second==0) pos[a[i]].second=i;
    }

    long long ans=1e18;
    pair<ll, ll> vitri;
    for (ll i=1; i<=maxn; i++)
    {
        ll u=0, v=0;
        for (ll j=i; j<=maxn; j+=i) 
        {
            if (pos[j].first>0)
            {
                if (u==0) u=pos[j].first; 
                else v=pos[j].first;
                if (v==0) v=pos[j].second;
                if (v>0) 
                {
                    if (1LL*a[u]*a[v]/i<ans) ans=1LL*a[u]*a[v]/i, vitri={u, v};
                    break;
                }
            }
        }
    }
    if (vitri.first>vitri.second) swap(vitri.first, vitri.second);
    cout<<vitri.first<<" "<<vitri.second<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    freopen("llcm.inp", "r", stdin);
    freopen("llcm.out", "w", stdout);
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}