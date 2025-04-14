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
Có k chương trình, mỗi chương trình chạy cold[i] nếu  chạy lần đầu tiên, hot[i] nếu có chương trình i chạy liền trước đó.
Bạn có 2 CPU, và n chương trình cần chạy a[i] (1<=a[i]<=k). Tìm thời gian chạy n chương trình nhỏ nhất.
Chương trình i chỉ có thể chạy nếu chương trình i-1 được hoàn thành.

Input
9
3 2
1 2 2
3 2
2 1
4 2
1 2 1 2
5 3
2 1
4 3
1 2 3 1
100 100 100
1 1 1
5 2
2 1 2 1 1
65 45
54 7
5 3
1 3 2 1 2
2 2 2
1 1 1
5 1
1 1 1 1 1
1000000000
999999999
5 6
1 6 1 4 1
3 6 4 1 4 5
1 1 1 1 4 1
1 3
3
4 5 6
1 2 3
8 3
3 3 3 1 2 3 2 1
10 10 8
10 10 5
Output
6
11
301
225
8
4999999996
11
6
63
In the second test case, we can use do the following:

Run program a1=1 on CPU 1. It takes cold1=5 seconds to run.
Run program a2=2 on CPU 2. It takes cold2=3 seconds to run.
Run program a3=1 on CPU 1. The last program run on this CPU was also program 1, so it takes hot1=2 seconds to run.
Run program a4=2 on CPU 2. The last program run on this CPU was also program 2, so it takes hot2=1 second to run.
In total, we need 5+3+2+1=11 seconds. We can show this is optimal.

Ý tưởng:
Gọi dp[i][j] là thời gian chạy ít nhất sao cho chương trình i chạy cuối cùng trên CPU 1 và chương j chạy cuối cùng trên CPU 2. (i>j)
Khởi tạo:
    dp[0][0]=0
    dp[1][0]=cold[a[1]]    
Công thức dp:
    Đặt chương trình i vào CPU 1:   
        Chương trình cuối cùng trên CPU 1 là i.
        Chương trinh cuối cùng trên CPU 2 là j.
        dp[i][j]=min(dp[i][j], dp[i-1][j] + cost(i-1, i))  Thời gian ít nhất của chương trình i-1 trên CPU 1 và chương trình j trên CPU 2
    Đặt chương trình i vào CPU 2:
        Chương trình cuối cùng trên CPU 1 là i-1.
        Chương trình cuối cùng trên CPU 2 là i.    => lần này hơi khác là chương trình i đặt trên CPU 2, nhưng đáp án tối ưu vẫn như nhau vì 
        nếu chương trình cuối cùng n đặt vào CPU 2 thì chúng ta có thể swap các chương trình trên CPU 1 và CPU 2
        dp[i][i-1]=min(dp[i][i-1], dp[i-1][j] + cost(j, i))  Thời gian ít nhất của chương trình i-1 trên CPU 1 và chương trình j trên CPU 2.
*/

ll n, k;
ll a[5005], cold[5005], hot[5005];
ll dp[5005][5005];

ll cost(ll u, ll v)
{
    if (a[u]==a[v]) return hot[a[v]];
    return cold[a[v]];
}

void solve()
{
    cin>>n>>k;
    
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=k; i++) cin>>cold[i];
    for (ll i=1; i<=k; i++) cin>>hot[i];

    
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++)
            dp[i][j]=1e18;
    
    dp[0][0]=0;
    dp[1][0]=cold[a[1]];
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=i-2; j++) 
        {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+cost(i-1, i));
            dp[i][i-1]=min(dp[i][i-1], dp[i-1][j]+cost(j, i));
        }
    }

    // for (ll i=0; i<=n; i++)
    // {
    //     for (ll j=0; j<=n; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    ll ans=1e18;
    for (ll i=0; i<n; i++) ans=min(ans, dp[n][i]);
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