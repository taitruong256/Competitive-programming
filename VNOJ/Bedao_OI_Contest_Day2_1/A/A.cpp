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
ll n, m, w[200005], d[200005], a[200005], x[200005], c[200005], id[200005], b;

bool comp(ll i, ll j)
{
    return d[i]<d[j];
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>w[i]>>d[i]>>a[i];
    cin>>m;
    for (ll i=1; i<=m; i++) cin>>x[i]>>c[i];
    cin>>b;

    for (ll i=1; i<=n; i++) id[i]=i;
    sort(id+1, id+n+1);
    ll ans=0;
    for (ll i=1; i<=m; i++)
    {
        ll mx=0, sum=0;
        for (ll j=1; j<=n; j++)
        {
            if (w[id[j]]>x[i]) continue;
            mx=max(mx, d[id[j]]);
            sum+=a[id[j]];
            ans=max(ans, -c[i]+sum-mx*b);
        }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("fishing.inp", "r", stdin);
    freopen("fishing.out", "w", stdout);
    solve();
    return 0;
}