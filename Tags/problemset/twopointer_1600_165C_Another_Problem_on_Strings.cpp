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

void solve()
{
    // ll k; cin>>k;
    // string s; cin>>s;
    // if (k==0)
    // {
    //     ll ans=0, cnt=0;
    //     for (auto c: s) 
    //     {
    //         if (c=='0') ++cnt, ans+=cnt;
    //         else cnt=0;
    //     }
    //     cout<<ans;
    //     return;
    // }

    // s=" "+s;
    // ll l=1, n=s.size()-1;
    // deque<ll> dq;
    // ll ans=0;
    // for (ll r=1; r<=n; r++)
    // {
    //     if (s[r]=='1') dq.push_back(r);
    //     while (dq.size()>k)
    //     {
    //         if (s[l]=='1') dq.pop_front();
    //         ++l;
    //     }
    //     if (dq.size()==k) ans+=dq.front()-l+1;  //cout<<l<<" "<<r<<" "<<dq.size()<<endl;
    // }
    // cout<<ans;

    ll k, n; cin>>k;
    string s; cin>>s;
    if (k==0)
    {
        ll ans=0, cnt=0;
        for (auto c: s) 
        {
            if (c=='0') ++cnt, ans+=cnt;
            else cnt=0;
        }
        cout<<ans;
        return;
    }

    n=s.size();
    s=" "+s;
    ll dp[n+5], cnt=0, ans=0;
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for (ll i=1; i<=n; i++)
    {
        if (s[i]=='1') ++cnt;
        dp[cnt]++;
        if (cnt>=k) ans+=dp[cnt-k];
    }  
    cout<<ans;
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