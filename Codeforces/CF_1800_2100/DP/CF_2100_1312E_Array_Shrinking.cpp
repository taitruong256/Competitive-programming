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
Cho mang A co n phan tu, moi thao tac duoc chon vi tri i sao cho a[i]=a[i+1], thay the hai so bang mot so a[i]+1
Hoi do dai nho nhat la bao nhieu.

Test:
Input
5
4 3 2 2 3
Output
2
In the first test, this is one of the optimal sequences of operations: 4 3 2 2 3 → 4 3 3 3 → 4 4 3 → 5 3.

Y tuong:
Goi f[i][j]: la so lon nhat va duy nhat con lai khi thay the trong doan [i, j]
    dp[i]: do dai nho nhat trong tien to [1..i] khi thuc hien thao tac tren
        dp[i]=i  //Khoi tao
        dp[i]=min(dp[i], dp[j-1]+1) khi f[j][i]>0  //doan [j, i] chi con 1 phan tu la f[j][i]
*/

ll dp[505], f[505][505], n, a[505];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) f[i][i]=a[i];
    for (ll len=2; len<=n; len++)
        for (ll l=1; l<=n-len+1; l++)
        {
            ll r=l+len-1;
            for (ll k=l; k<r; k++)
                if (f[l][k]==f[k+1][r] && f[l][k]!=0) 
                    f[l][r]=f[l][k]+1;
        }
    
    for (ll i=1; i<=n; i++)
    {
        dp[i]=i;
        for (ll j=1; j<=i; j++)
            if (f[j][i]>0)
                dp[i]=min(dp[i], dp[j-1]+1);
    }

    cout<<dp[n];
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