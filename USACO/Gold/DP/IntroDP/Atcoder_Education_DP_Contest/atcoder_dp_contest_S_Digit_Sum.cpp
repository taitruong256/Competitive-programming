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
ll dp[10005][105][3], n, d;
string s, k;
 
ll calc(ll pos, ll sum, ll is_smaller)
{             
    if (pos == n) 
    {
        if (sum==0) return 1;
        return 0;
    }
    if (dp[pos][sum][is_smaller] != -1) return dp[pos][sum][is_smaller];
    ll limit = 9;
    if (is_smaller == 0) limit = s[pos]-'0';
    ll ans=0;
    for (ll i=0; i<=limit; i++)
    {
        ll new_is_smaller = is_smaller | (i<limit);
        ll cnt=calc(pos+1, (sum+i)%d, new_is_smaller);
        ans += cnt;
        ans%=mod;
    }
    return dp[pos][sum][is_smaller] = ans;
}
 
ll query(string k)
{
    s=k;
    n = s.size();                   
    memset(dp, -1, sizeof(dp));
    return calc(0, 0, 0);
}
 
void solve()
{
    cin>>k>>d;
    cout<<(query(k)-1+mod)%mod;
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