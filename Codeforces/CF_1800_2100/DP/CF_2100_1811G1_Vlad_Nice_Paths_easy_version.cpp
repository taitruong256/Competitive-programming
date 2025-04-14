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
ll n, k, dp[105][105], col[105], c[105][105];

/*
Co n vien gach, moi vien co mau col[i], va so nguyen k.
Goi mot day p[1]<p[2]< ...<p[m] (m la boi cua k) la tot neu co the chia thanh cac block sao cho:
    -c[p[1]]==c[p[2]]==...==c[p[k]]
    -c[p[k+1]]==c[p[k+2]]==...==c[p[2*k]]
    -c[p[m-k+1]]]==c[p[m-k+2]]==...==c[p[m*k]]
Nhiem vu cua ban la tim so duong di dep co do dai la dai nhat (mod 1e9+7)

Input
5
5 2
1 2 3 4 5
7 2
1 3 1 3 3 1 3
11 4
1 1 1 1 1 1 1 1 1 1 1
5 2
1 1 2 2 2
5 1
1 2 3 4 5
Output
1
4
165
3
1

Y tuong:
Goi dp[i][j]: so duong di dep cua tien to [1..i], co so block la j
    -dp[i][j]=dp[j-1][j-1]*c[cnt-1][k-1] voi j<i, cnt la so luong mau giong nhau voi col[i] doan [j..i]
*/

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>col[i];
    
    dp[0][0]=1;
    for (ll block=1; block<=n/k; block++)
    {
        for (ll i=k; i<=n; i++)
        {
            ll cnt=0;
            for (ll j=i; j>=1; j--)
            {
                if (col[i]==col[j]) ++cnt;
                if (cnt>=k) 
                {
                    dp[i][block]=(dp[i][block]+dp[j-1][block-1]*c[cnt-1][k-1])%mod;
                }
            }
        }
    }

    // for (ll i=0; i<=n; i++)
    // {
    //     for (ll j=0; j<=n/k; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    for (ll block=n/k; block>=0; block--)
    {
        ll ans=0;
        for (ll i=0; i<=n; i++) ans+=dp[i][block], ans%=mod;
        if (ans>0)
        {
            cout<<ans<<endl;
            break;
        }
    }

    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=n; j++)
            dp[i][j]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    c[0][0]=1;
    for (ll i=1; i<=100; i++)
    {
        c[i][0]=1;
        c[i][i]=1;
        for (ll j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}