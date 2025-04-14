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

ll n, q, a[500005], k, m, pos, pref[500005], suff[500005];

ll find_last(ll l, ll r, ll x)
{
    ll ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (2*k-a[mid]>=x) ans=mid, l=mid+1;
        else r=mid-1;
    }
    return ans;
}

bool check(ll mid)
{
    pos=upper_bound(a+1, a+n+1, k)-a;
    ll cnt=0;
    for (ll i=1; i<pos; i++) if (a[i]<=mid) ++cnt;
    for (ll i=pos; i<=n; i++) if (2*k-a[i]<=mid) ++cnt;
    return cnt>=m;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    for (ll i=n; i>=1; i--) suff[i]=suff[i+1]-a[i];
    
    while (q--)
    {
        cin>>k>>m;
        ll l=-2e9, r=2e9, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (check(mid)==true) ans=mid, r=mid-1;
            else l=mid+1;
        }
        ll cnt=0, sum=0;
        for (ll i=1; i<pos; i++) if (a[i]<ans) sum+=a[i], ++cnt;
        for (ll i=pos; i<=n; i++) if (2*k-a[i]<ans) sum+=2*k-a[i], ++cnt;
        sum+=ans*(m-cnt);
        cout<<sum<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}