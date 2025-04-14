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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n, m; cin>>n>>m;
    ll cnt[n+5], cost[n+5], sum=0;
    for (ll i=1; i<=n; i++) cin>>cnt[i], sum+=cnt[i];
    for (ll i=1; i<=n; i++) cin>>cost[i];
    set<pair<ll, ll>> st;
    for (ll i=1; i<=n; i++) st.insert({cost[i], i});

    while (m--)
    {
        ll type, d; cin>>type>>d;
       
        ll ans=0;
        if (d<=cnt[type])
        {
            ans=d*cost[type];
            cnt[type]-=d;
            sum-=d;
            d=0;
            if (cnt[type]==0) st.erase({cost[type], type});
        }
        else 
        {
            ll sl=min(d, cnt[type]);
            ans+=sl*cost[type];
            cnt[type]-=sl;
            sum-=sl;
            if (cnt[type]==0) st.erase({cost[type], type});
            d-=sl;
            while (d>0 && !st.empty())
            {
                auto it=*(st.begin());
                ll sl=min(d, cnt[it.second]);
                ans+=sl*cost[it.second];
                cnt[it.second]-=sl;
                sum-=sl;
                if (cnt[it.second]==0) st.erase({cost[it.second], it.second});
                d-=sl;
            }
        }
        
        if (d==0) cout<<ans<<endl; else cout<<0<<endl;
        
        // cout<<endl; for (ll i=1; i<=n; i++) cout<<cnt[i]<<" "; cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}