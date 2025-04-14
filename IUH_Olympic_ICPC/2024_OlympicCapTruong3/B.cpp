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

ll n, m, x[500005], s[500005], f[500005], c[500005], r[500005];

bool check(ll mid)
{
    for (ll i=1; i<=m; i++)
    {
        ll dist=0, cnt=r[i];
        for (ll j=s[i]+1; j<=f[i]; j++) 
        {
            if ((x[j]-x[j-1])*c[i]>mid) return false;
            if (dist+(x[j]-x[j-1])*c[i]<=mid) dist+=(x[j]-x[j-1])*c[i];
            else 
            {
                if (cnt>0) --cnt, dist=(x[j+1]-x[j])*c[i];
                else return false;
            }
        }
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>x[i];
    x[n+1]=x[n];
    for (ll i=1; i<=m; i++) cin>>s[i]>>f[i]>>c[i]>>r[i];
    ll l=0, r=1e15, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    assert(ans!=-1);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    solve();
    return 0;
}