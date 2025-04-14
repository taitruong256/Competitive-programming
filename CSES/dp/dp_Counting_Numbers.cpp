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
ll dp[20][20][3][3], n, l, r, d;
string s;

ll calc(ll pos, ll digit, ll is_smaller, ll is_empty)
{            
    if (pos == n) return 1;
    if (dp[pos][digit][is_smaller][is_empty] != -1) return dp[pos][digit][is_smaller][is_empty];
    ll limit = 9;
    if (is_smaller == 1) limit = s[pos]-'0';
    ll ans=0;
    for (ll i=0; i<=limit; i++)
    {
        if ((i==digit) && (is_empty==0)) continue;
        ll new_is_smaller = is_smaller & (i==limit);
        ll new_is_empty = is_empty & (i==0);
        ans += calc(pos+1, i, new_is_smaller, new_is_empty);
    }
    return dp[pos][digit][is_smaller][is_empty] = ans;
}

ll query(ll x)
{
    if (x==-1) return 0;
    s = to_string(x);   
    n = s.size();                   
    memset(dp, -1, sizeof(dp));
    return calc(0, 0, 1, 1);
}

void solve()
{
    cin>>l>>r;  
    cout<<query(r)-query(l-1);
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