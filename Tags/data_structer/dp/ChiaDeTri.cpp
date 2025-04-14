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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, w[20005], d[20005], sumW[20005], sumD[20005], sumWS[20005], best[20005];

ll cost(ll l, ll r)
{
    return sumWS[l]-sumWS[r]-sumD[r]*(sumW[l]-sumW[r]);
}

ll eval(ll l, ll r)
{
    return cost(1, l)+cost(l+1, r)+cost(r+1, n+1);
}

void calc(ll l, ll r, ll from, ll to)
{
    if (l>r) return;
    ll mid=(l+r)/2;
    best[mid]=from;
    for (ll i=from; i<=to; i++)
        if (eval(mid, i)<eval(mid, best[mid])) 
            best[mid]=i;
    calc(l, mid-1, from, best[mid]);
    calc(mid+1, r, best[mid], to);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>w[i]>>d[i];
    for (ll i=n; i>=1; i--) 
    {
        sumW[i]=sumW[i+1]+w[i];
        sumD[i]=sumD[i+1]+d[i];
        sumWS[i]=sumWS[i+1]+w[i]*sumD[i];
    }
    calc(1, n, 1, n);
    ll ans=LLONG_MAX;
    for (ll i=1; i<=n; i++) ans=min(ans, eval(i, best[i]));
    for (ll i=1; i<=n; i++) cout<<i<<" "<<best[i]<<endl;
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