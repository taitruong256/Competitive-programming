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
ll cnt[100005], pref[100005], suff[100005], a[100005], n;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll ans;
    ans=0;
    for (ll i=1; i<=n; i++)
    {
        ll x=a[i];
        for (ll j=1; j*j<=x; j++) if (x%j==0)
        {
            ++cnt[j]; 
            if (cnt[j]>=2) ans=max(ans, j);
            if (j!=x/j) ++cnt[x/j];
            if (cnt[x/j]>=2) ans=max(ans, x/j);
        }
        pref[i]=ans;
    }

    for (ll j=0; j<=1e5; j++) cnt[j]=0;
    ans=0;
    for (ll i=n; i>=1; i--)
    {
        ll x=a[i];
        for (ll j=1; j*j<=x; j++) if (x%j==0)
        {
            ++cnt[j]; 
            if (cnt[j]>=2) ans=max(ans, j);
            if (j!=x/j) ++cnt[x/j];
            if (cnt[x/j]>=2) ans=max(ans, x/j);
        }  
        suff[i]=ans;
    }
    ans=0;
    for (ll i=1; i<=n; i++) ans=max(ans, pref[i]+suff[i+1]);
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