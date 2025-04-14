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

void solve()
{
    /*
    Bai toan: cho mang a co n phan tu. 
    Trong moi thao tac:
    Chon mot phan tu x trong mang a, xoa x di va thay bang hai so y+z=x+k
    Cach giai:
    Dat:
        x=x'+k, y=y'+k, z=z'+k
    Ta co y+z=x+k -> y'+k+z'+k=x'+k+k 
                  -> y'+z'=x'
                  -> dua bai toan ve dang co dien voi a[i]=a[i]-k, k=0
                  -> dap an = tong(a[i]/gcd(a))-n 
    */


    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    bool lon=false, bang=false, nho=false;
    for (ll i=1; i<=n; i++)
    {
        a[i]-=k;
        if (a[i]<0) nho=true;
        else if (a[i]==0) bang=true;
        else lon=true;
    }
    if (nho+bang+lon>1) cout<<-1<<endl;
    else if (bang==true) cout<<0<<endl;
    else 
    {
        ll ans=0, g=0;
        for (ll i=1; i<=n; i++) g=__gcd(g, abs(a[i]));
        for (ll i=1; i<=n; i++) ans+=abs(a[i])/g-1;
        cout<<ans<<endl;
    }
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