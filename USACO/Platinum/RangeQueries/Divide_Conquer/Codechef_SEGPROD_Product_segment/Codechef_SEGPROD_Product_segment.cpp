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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, p, q, a[1000005], b[1000005];
ll mask[1000005], dat[25][1000005], ans[1000005], le[1000005], ri[1000005];

void divide_and_conquer(ll l, ll r, ll level)
{
    if (l==r) return;
    ll mid=(l+r)/2;
    dat[level][mid]=a[mid]%p;
    for (ll i=mid-1; i>=l; i--) dat[level][i]=(a[i]*dat[level][i+1])%p;
    dat[level][mid+1]=a[mid+1]%p;
    for (ll i=mid+2; i<=r; i++) dat[level][i]=(a[i]*dat[level][i-1])%p;
    for (ll i=mid+1; i<=r; i++) mask[i]^=(1LL<<level);
    divide_and_conquer(l, mid, level+1);
    divide_and_conquer(mid+1, r, level+1);
}

void solve()
{
    cin>>n>>p>>q;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<q/64+2; i++) cin>>b[i];
    divide_and_conquer(0, n-1, 0);
    ll l=0, r=0, x=0;
    for (ll i=0; i<q; i++)
    {
        if (i%64==0) l=(b[i/64]+x)%n, r=(b[i/64+1]+x)%n;
        else l=(l+x)%n, r=(r+x)%n;
        if (l>r) swap(l, r);
        if (l==r) x=(a[l]+1)%p;
        else 
        {
            ll level=__builtin_ctz(mask[l]^mask[r]);
            x=(dat[level][l]*dat[level][r]+1)%p;
        }
    }
    cout<<x<<endl;
    for (ll i=0; i<n; i++) mask[i]=0;
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