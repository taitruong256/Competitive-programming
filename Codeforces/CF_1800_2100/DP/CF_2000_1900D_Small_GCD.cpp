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
Van de: Cho mang a co n phan tu
Goi f(a, b, c)=gcd(a, b)
Tinh tong f(a[i], a[j], a[k]) voi i<j<k

Test:
Input:
2
5
2 3 6 12 17
8
6 12 8 10 15 12 18 16
Output:
24
203

Giai thich:
In the first test case, the values of f are as follows:
i=1, j=2, k=3, f(ai,aj,ak)=f(2,3,6)=gcd(2,3)=1;
i=1, j=2, k=4, f(ai,aj,ak)=f(2,3,12)=gcd(2,3)=1;
i=1, j=2, k=5, f(ai,aj,ak)=f(2,3,17)=gcd(2,3)=1;
i=1, j=3, k=4, f(ai,aj,ak)=f(2,6,12)=gcd(2,6)=2;
i=1, j=3, k=5, f(ai,aj,ak)=f(2,6,17)=gcd(2,6)=2;
i=1, j=4, k=5, f(ai,aj,ak)=f(2,12,17)=gcd(2,12)=2;
i=2, j=3, k=4, f(ai,aj,ak)=f(3,6,12)=gcd(3,6)=3;
i=2, j=3, k=5, f(ai,aj,ak)=f(3,6,17)=gcd(3,6)=3;
i=2, j=4, k=5, f(ai,aj,ak)=f(3,12,17)=gcd(3,12)=3;
i=3, j=4, k=5, f(ai,aj,ak)=f(6,12,17)=gcd(6,12)=6.
The sum over all triples is 1+1+1+2+2+2+3+3+3+6=24.

Y tuong:
-Goi dp[i] so bo ba (a, b, c) co gcd(a, b) la i => dap an tong(dp[i]*i)
-Vi khong quan trong thu tu nen sap xep a tang dan 
-Dung mang vector de luu cac uoc cua a[i] 
-Voi moi vi tri i, ta co dinh vi tri do co gia tri b=a[i]. 
    +duyet qua tung uoc j cua a[i] 
        *so cach chon ben trai = cnt[j]
        *so cach chon ben phai = n-i
        *dp[j]=cnt[j]*(n-i)  // dp[j] luc nay la so bo ba co gcd(a, b) la boi cua j
-Dung san de tru di nhung bo ba la boi cua dp[i]
*/

vector<ll> divisor[100005];
ll n, a[100005], dp[100005], cnt[100005];

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    for (ll i=1; i<=n; i++)
    {
        for (auto j: divisor[a[i]]) 
        {
            dp[j]+=cnt[j]*(n-i);
            ++cnt[j];
        }
    }

    for (ll i=a[n]; i>=1; i--)
        for (ll j=2*i; j<=a[n]; j+=i) dp[i]-=dp[j];

    ll ans=0;
    for (ll i=1; i<=a[n]; i++) ans+=dp[i]*i;
    cout<<ans<<endl;

    for (ll i=1; i<=a[n]; i++) dp[i]=cnt[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    for (ll i=1; i<=100000; i++) 
        for (ll j=i; j<=100000; j+=i) 
            divisor[j].push_back(i);

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}