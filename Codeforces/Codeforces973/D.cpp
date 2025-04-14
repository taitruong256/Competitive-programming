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

ll n, a[200005];

bool check_max(ll mid)
{
    ll du=0;
    for (ll i=1; i<=n; i++)
    {
        if (a[i]>=mid) du+=(a[i]-mid);
        else du-=min(mid-a[i], du);
    }
    if (du>0) return 0;
    return 1;
}

bool check_min(ll mid)
{
    ll du=0;
    for (ll i=1; i<=n; i++)
    {
        if (a[i]>=mid) du+=(a[i]-mid);
        else if (du<mid-a[i]) return 0;
        else du-=min(mid-a[i], du);
    }
    return 1;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll l=1, r=*max_element(a+1, a+n+1), ans_max=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check_max(mid)==true) ans_max=mid, r=mid-1;
        else l=mid+1;
    }
    ll du=0;
    if (ans_max!=-1)
    {
        for (ll i=1; i<=n; i++) 
        {
            if (a[i]>=ans_max) 
            {
                du+=(a[i]-ans_max);
                a[i]=ans_max;
            }
            else 
            {
                ll x=min(du, ans_max-a[i]);
                a[i]+=x;
                du-=x;
            }
        }
    }

    l=1, r=ans_max;
    ll ans_min=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check_min(mid)==true) ans_min=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans_max-ans_min<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}