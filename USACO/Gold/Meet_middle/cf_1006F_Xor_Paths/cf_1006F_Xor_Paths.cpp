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

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    ll moves=n+m-2;
    if (moves==0)
    {
        cout<<(a[1][1]==k);
        return;
    }

    map<ll, ll> cnt[n+5][m+5];
    ll left=moves/2;
    for (ll i=0; i<(1LL<<left); i++)
    {
        ll sumxor=a[1][1], r=1, c=1, check=1;
        for (ll j=0; j<left; j++) 
        {
            if (i&(1LL<<j)) ++r;
            else ++c;
            if (r>n || c>m)
            {
                check=0;
                break;
            }
            sumxor^=a[r][c];
        }
        if (check==1) cnt[r][c][sumxor]+=1;
    }
    
    ll right=moves-left-1, ans=0;
    for (ll i=0; i<(1LL<<right); i++)
    {
        ll sumxor=a[n][m], r=n, c=m, check=1;
        for (ll j=0; j<right; j++) 
        {
            if (i&(1LL<<j)) --r;
            else --c;
            if (r<1 || c<1)
            {
                check=0;
                break;
            }
            sumxor^=a[r][c];
        }
        if (check==1) 
        {
            if (r>1) ans+=cnt[r-1][c][k^sumxor];
            if (c>1) ans+=cnt[r][c-1][k^sumxor];
        }
    }
    cout<<ans;
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