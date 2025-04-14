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
const ll mod = 998244353;
ll n, a[105][105], dp[105][105];

/*
Có bao nhiêu xâu nhị phân độ dài n, thõa mãn:
    -Nếu a[i][j]==1, s[i..j] phải giống nhau
    -Nếu a[i][j]==2, s[i..j] phải có ít nhất 2 phần tử khác nhau
    -Nếu a[i][j]==0, không có ràng buộc gì

Input
3
1 0 2
1 0
1
Output
6

Input
3
1 1 2
1 0
1
Output
2

In the first example, the strings meeting the constraints are 001, 010, 011, 100, 101, 110.

In the second example, the strings meeting the constraints are 001, 110.

Ý tưởng: 
Gọi dp[i][j] là số cách chọn i phần tử đầu tiên sao cho phần tử cuối cùng khác s[i] là s[j].
    -dp[1][0]=2 (vì chọn 1 phần tử đầu tiên, phần tử s[0] khác s[1] có 2 cách là '0' và '1' - giả sử s[0] là rỗng)
    -Nếu đặt ký tự s[i+1]==s[i]:
        dp[i+1][j]+=dp[i][j]
    -Nếu đặt ký tự s[i+1]!=s[i]:
        dp[i+1][i]+=dp[i][j]
*/

bool check(ll x, ll y)
{
    for (ll i=1; i<=y; i++)
    {
        if (i<=x && a[i][y]==1) return false;
        if (i>x && a[i][y]==2) return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=i; j<=n; j++)
            cin>>a[i][j];
    
    for (ll i=1; i<=n; i++) if (a[i][i]==2)
    {
        cout<<0<<endl;
        return;
    }

    dp[1][0]=2;
    for (ll i=1; i<=n-1; i++)
        for (ll j=0; j<=i-1; j++)
        {
            if (check(j, i+1)) dp[i+1][j]+=dp[i][j], dp[i+1][j]%=mod;
            if (check(i, i+1)) dp[i+1][i]+=dp[i][j], dp[i+1][i]%=mod;
        }

    ll ans=0;
    for (ll i=0; i<=n-1; i++) ans=(ans+dp[n][i])%mod;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}