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

/*
Mot phu thuy ban dau co mana nuoc=0, lua=0, ,moi giay phu thuy hoi +w mana nuoc, +f mana lua.
Co n quai vat co suc manh s[i], phu thuy co the tieu diet quai vat neu w>=s[i] hoac f>=s[i]
Hoi so giay it nhat de tieu diet toan bo quai vat

Test
Input
4
2 3
3
2 6 7
37 58
1
93
190 90
2
23 97
13 4
4
10 10 2 45
Output
3
2
1
5

Y tuong:
Co the doi toi giay cuoi cung de tieu diet toan bo quai vat, khong tieu ton mana dan dan.
Ta uu tien dung mana nuoc de tieu diet quai vat truoc, quai vat con lai dung mana lua.
Dung dp cai tui de giai quyet.
*/

void solve()
{
    ll w, f; cin>>w>>f;
    ll n; cin>>n;
    ll s[n+5], sum=0;
    for (ll i=1; i<=n; i++) cin>>s[i], sum+=s[i];
    vector<bool> dp(sum+5, 0);
    dp[0]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=sum; j>=s[i]; j--)
            dp[j]=(dp[j-s[i]] | dp[j]);

    ll ans=1e18;
    for (ll i=0; i<=sum; i++) if (dp[i]==1) ans=min(ans, max((i+w-1)/w, (sum-i+f-1)/f));
    cout<<ans<<endl;
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