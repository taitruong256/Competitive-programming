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
ll n, a[1000005], cnt[1000005], dp[1000005];
bool bad[1000005];

/*
Van de: cho mang a co n phan tu, hay tim so cap (i<j) sao cho khong duoc co a[i]%a[k]==0 && a[j]%a[k]==0

Test:
------------------------------------------------------------------------
Input:
------------------------------------------------------------------------
6
4
2 4 4 4
4
2 3 4 4
9
6 8 9 4 6 8 9 4 9
9
7 7 4 4 9 9 6 2 9
18
10 18 18 15 14 4 5 6 8 9 10 12 15 16 18 17 13 11
21
12 19 19 18 18 12 2 18 19 12 12 3 12 12 12 18 19 16 18 19 12
------------------------------------------------------------------------
Output:
------------------------------------------------------------------------
0
3
26
26
124
82
------------------------------------------------------------------------

Y tuong:
-neu a[i]%a[k]==0 && a[j]%a[k]==0 thi a[k] la uoc cua gcd(a[i], a[j])
-goi dp[g] la so cap co gcd la g, cnt[a[i]] la so lan xuat hien cua a[i] trong mang
    +s=cnt[g]+cnt[2*g]+...cnt[k*g] (k*g<=n)
    +dp[g]=s*(s-1)/2-dp[2*g]-...-dp[k*g] (k*g<=n)
-dap an la tong cua dp[g] thoa man khong co phan tu a[k] la uoc cua g
*/

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        ++cnt[a[i]];
        bad[a[i]]=1;
    }

    for (ll i=1; i<=n; i++) 
        for (ll j=i; j<=n; j+=i) bad[j]|=bad[i];

    for (ll i=n; i>=1; i--)
    {
        ll s=0;
        for (ll j=i; j<=n; j+=i) s+=cnt[j];
        dp[i]=s*(s-1)/2;
        for (ll j=i*2; j<=n; j+=i) dp[i]-=dp[j];
    }

    ll ans=0;
    for (ll i=1; i<=n; i++) if (bad[i]==false) ans+=dp[i];
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) cnt[i]=dp[i]=bad[i]=0;
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