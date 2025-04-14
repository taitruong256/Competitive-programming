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
const ll ZERO = 100000;
ll n, a[305], dp[305][2*ZERO+5];

/*
Cho mảng a có n phần tử.
Trong mỗi thao tác i từ 1 đến n-2, cộng a[i+1] với phần tử liền kề (i/i+2) và trừ a[i+1] với phần tử liền kề khác (i+2/i).
Tìm số mảng khác nhau sau khi thực hiện n-2 thao tác.

Input
4
1 1 1 1
Output
3

Input
5
1 2 3 5 0
Output
7

Ý tưởng: 
Khi thực hiện thao tác i, các phần tử trước <=i và >=i+3 không thay đổi.
Gọi dp[i][x][y]: số mảng khác nhau của tiền tố a[1..i], giá trị a[i+1] là x, a[i+2] là y.
Note: **Áp dụng thao tác i, a[i], a[i+1], a[i+2] thay đổi**
Áp dụng thao tác i+1, a[i+1], a[i+2, a[i+3] thay đổi
    Khi cộng a[i+2] vào a[i+3]
        dp[i][x][y]+=dp[i+1][y][a[i+3]+y] 
    Khi trừ a[i+2] vào a[i+3]
        dp[i][x][y]+=dp[i+1][y][a[i+3]-y]. Lưu ý là nếu y==0 thì chỉ cộng 1 lần vì a[i+3]+y=a[i+3]-y.
    => solution O(n^3*sumA)
    => có thể loại bỏ chiều y để O(n^2*sumA)
    => tổng có thể âm nên ta cần cộng thêm n*max(a[i]) = 90000. Khai báo mảng dp[i][2*90000].
*/

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    dp[2][a[2]+ZERO]=1;
    for (ll i=2; i<=n; i++)
    {
        for (ll j=-90000; j<=90000; j++) if (dp[i][j+ZERO]!=0)
        {
            dp[i+1][a[i+1]+j+ZERO]+=dp[i][j+ZERO];
            dp[i+1][a[i+1]+j+ZERO]%=mod;
            if (j!=0)
            {
                dp[i+1][a[i+1]-j+ZERO]+=dp[i][j+ZERO];
                dp[i+1][a[i+1]-j+ZERO]%=mod;
            }
        }
    }
    ll ans=0;
    for (ll j=-90000; j<=90000; j++) ans=(ans+dp[n][j+ZERO])%mod;
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