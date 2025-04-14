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

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n+5), dp(n+5), sum(n+5), pref(n+5);
    /*
    dp[i]: so mang con (co the khong lien tiep) co a[i] la phan tu cuoi cung
    sum[i]: tong tien to cua mang con thoa a[k]<a[j]<...<a[i] (tang dan theo thu tu stack)
    pref[i]: tong tien to cua dp tu 1 den i
    */
    for (ll i=1; i<=n; i++) cin>>a[i];
    dp[1]=1;
    sum[1]=1;
    pref[1]=1;  //vi tri 1 co 1 cach 
    vector<pair<ll, ll>> stk;
    stk.push_back({a[1], 1});
    for (ll i=2; i<=n; i++)
    {
        while (!stk.empty() && stk.back().first>a[i]) stk.pop_back();  //tim vi tri phan tu a[j]<a[i] o ben trai (luu y mang a phan biet)
        if (stk.empty())
        {
            //neu a[i] la phan tu nho nhat: so cach chon bang tong tien to toi i-1 cong them 1 
            dp[i]=(pref[i-1]+1)%mod;
            sum[i]=dp[i];
            pref[i]=(pref[i-1]+dp[i])%mod;
        }
        else 
        {
            ll j=stk.back().second;
            //pref[i-1]-pref[j]: so cach chon phan tu nam giua j+1 va i-1 (vi cac phan tu nay lon hon a[i] nen co the xoa di con lai a[i])
            //sum[j] (goi f[i]=j): so cach chon mang con ma ket thuc o f[i], f[f[i]], f[f[f[i]]] 
            //ma doan (f[i]+1, i), (f[f[i]]+1, i), (f[f[f[i]]]+1, i) giu nguyen
            dp[i]=(pref[i-1]-pref[j]+sum[j]+mod)%mod;
            sum[i]=(sum[j]+dp[i])%mod;
            pref[i]=(pref[i-1]+dp[i])%mod;
        }
        stk.push_back({a[i], i});
    }
    ll ans=0, mn=1e18;
    for (ll i=n; i>=1; i--)
    {
        mn=min(mn, a[i]);  //a[i]==mn nghia la tat ca phan tu sau a[i] nho hon a[i] nen co the xoa het phia sau
                           //cong vao dap an dp[i]
        if (a[i]==mn) ans=(ans+dp[i])%mod;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}