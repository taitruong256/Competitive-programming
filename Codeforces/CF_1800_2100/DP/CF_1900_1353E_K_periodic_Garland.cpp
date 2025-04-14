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
Cho chuoi s chi gom ky tu 0 va 1.
Chuoi goi la dep neu moi cap khoang cach co gia =1 deu =k. Moi thao tac duoc doi 0->1, 1->0.
Tim so thao tac it nhat de chuoi dep.

Test:
Input
6
9 2
010001010
9 3
111100000
7 4
1111111
10 3
1001110101
1 1
1
1 1
0
Output
1
2
5
4
0
0

Y tuong:
Goi dp[i] la so thao tac it nhat de tao thanh chuoi dep cua chuoi [1..i] ma s[i]='1'
    -neu i<=k:
        dp[i]=(s[i]=='0'+cnt[i-1]): vi tri bang '1', [1..i-1] bang '0'
    -nguoc lai i>k:
        dp[i]=min(dp[i-k], cnt[i-k])+cnt[i-1]-cnt[i-k]+(s[i]=='0'):
            +min(dp[i-k], cnt[i-k]): dap an toi uu o vi tri i-k, hoac bien toan bo [1..i] bang '0'
            +(cnt[i-1]-cnt[i-k]): toan bo '1' doan [i-k+1..i-1] bien thanh '0'
            +vi tri s[i] bat buoc bang 1
    ans=min(dp[i]+cnt[n]-cnt[i]): dap an toi uu o tien to s[1..i], s[i+1..n] bang '0'
*/

ll n, k, dp[1000005], cnt[1000005], ans;

void solve()
{
    cin>>n>>k;
    string s; cin>>s; s=" "+s;
    for (ll i=1; i<=n; i++) cnt[i]=cnt[i-1]+(s[i]=='1');
    ans=cnt[n];
    for (ll i=1; i<=n; i++)
    {
        if (i<=k) dp[i]=(s[i]=='0')+cnt[i-1];
        else dp[i]=min(dp[i-k], cnt[i-k])+cnt[i-1]-cnt[i-k]+(s[i]=='0');
        ans=min(ans, dp[i]+cnt[n]-cnt[i]);
    }      
    cout<<ans<<endl;

    for (ll i=1; i<=n; i++) dp[i]=cnt[i]=0;
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