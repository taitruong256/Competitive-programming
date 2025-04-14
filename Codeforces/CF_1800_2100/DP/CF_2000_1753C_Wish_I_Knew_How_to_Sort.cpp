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

/*
Cho mảng a có n phần tử 0 và 1. 
Trong mỗi thao tác:
    -Bạn được chọn ngẫu nhiên 2 chỉ số i<j
    -Nếu a[i]>a[j] swap(a[i], a[j])
Tính giá trị kỳ vọng để sắp sếp mảng. (p/q => p*q^-1%mod)

Input
3
3
0 1 0
5
0 0 1 1 1
6
1 1 1 0 0 1
Output
3
0
249561107

Ý tưởng:
Gọi k là số lượng số 0 trong mảng.
Mục tiêu của ta là sắp sếp k số 0 ở đầu, n-k số 1 ở cuối.
Xét tiền tố k của mảng, có j số 1, sau một thao tác thì j không thể tăng.
Gọi R[j] là biến ngẫu nhiên số lượng thao tác để chuyển giảm j số 1 trong tiền tố k giảm từ j tới j-1.
Xác suất chọn cặp như vậy là: p[j]=(j*j)/(n*(n-1)/2) => chọn j số 1 ở trong tiền tố k và j số 0 hậu tố (n-k) / số cách chọn 2 cặp chỉ số ngẫu nhiên nC2.

E[R[j]]=p[j]*1 + (1-p[j])*(1+E[R[j]])       //lưu ý kỳ vọng của hằng số bằng hằng số E(1+R[j])=1+E[R[j]]
       =(2*j*j)/(n*(n-1)) + 1 + E[R[j]] - (2*j*j)/(n*(n-1)) - (2*j*j)/(n*(n-1))*E[R[j]]
_______=________________       _______   ________________
E[R[j]]*(2*j*j)/(n*(n-1)) = 1
E[R[j]]=(n*(n-1))/(2*j*j)
E[R]=sum(E[R[j]])
*/

ll binpow(ll x, ll n, ll mod)
{
    x%=mod;
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll zeros=0;
    for (ll i=1; i<=n; i++) if (a[i]==0) ++zeros;
    ll ans=0, ones=0;
    for (ll i=1; i<=zeros; i++)
    {
        if (a[i]==1)
        {
            ones+=1;
            ll res=0;
            res=n*(n-1)/2%mod;
            res=(res*binpow(ones*ones, mod-2, mod))%mod;
            ans=(ans+res)%mod;
        }
    }    
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