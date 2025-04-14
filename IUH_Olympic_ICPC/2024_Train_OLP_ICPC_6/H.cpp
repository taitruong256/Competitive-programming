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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n, k; cin>>n>>k;
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    sort(a+1, a+n+1);
    ll ans=0, cnt=0;
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j++) 
            if (abs(a[i].first-a[j].first)<k && abs(a[i].second-a[j].second)<k) 
            {
                ++cnt;
                ll x1=max(a[i].first-k/2, a[j].first-k/2);
                ll x2=min(a[i].first+k/2, a[j].first+k/2);
                ll y1=max(a[i].second-k/2, a[j].second-k/2);
                ll y2=min(a[i].second+k/2, a[j].second+k/2);
                ans=(x2-x1)*(y2-y1);
            }
    if (cnt==0) cout<<0;
    else if (cnt==1) cout<<ans;
    else if (cnt>1) cout<<-1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}