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
ll n, q, a[200005], dat[20][200005], mask[200005];

void divide_and_conquer(ll l, ll r, ll level)
{
    if (l==r) return;
    ll mid=(l+r)/2;
    dat[level][mid]=a[mid];
    for (ll i=mid-1; i>=l; i--) dat[level][i]=min(a[i], dat[level][i+1]);
    dat[level][mid+1]=a[mid+1];
    for (ll i=mid+2; i<=r; i++) dat[level][i]=min(a[i], dat[level][i-1]);
    for (ll i=mid+1; i<=r; i++) mask[i]^=1LL<<level;
    divide_and_conquer(l, mid, level+1);
    divide_and_conquer(mid+1, r, level+1);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    divide_and_conquer(1, n, 0LL);
    while (q--)
    {
        ll l, r; cin>>l>>r;
        if (l==r) cout<<a[l]<<endl;
        else 
        {
            ll level=__builtin_ctz(mask[l]^mask[r]);
            cout<<min(dat[level][l], dat[level][r])<<endl;
        }
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}