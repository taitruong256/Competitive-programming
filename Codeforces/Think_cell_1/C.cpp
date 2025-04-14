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
ll n, pref[10005], suff[10005];
string s;

ll f(ll x, ll y)
{
    for (ll i=0; i<=n+1; i++) pref[i]=suff[i]=0;
    for (ll i=x; i<=y; i++)
    {
        pref[i]=pref[i-1];
        if (s[i]=='0') continue;
        ll check=1;
        for (ll j=i-1; j>=x; j--) 
        {
            ll mot=pref[i]-pref[j-1];
            ll khong=i-j-mot;
            if (mot>khong) check=0;
        }
        pref[i]+=check;
    }

    for (ll i=y; i>=x; i--)
    {   
        suff[i]=suff[i+1];
        if (s[i]=='0') continue;
        ll check=1;
        for (ll j=i+1; j<=y; j++) 
        {
            ll mot=suff[j]-suff[i-1];
            ll khong=j-i-mot;
            if (mot>khong) check=0;
            // cout<<i<<" "<<j<<"              "<<khong<<" "<<mot<<" "<<check<<endl;
        }
        suff[i]+=1;
    }
    // cout<<s.substr(x, y-x+1)<<endl;
    // for (ll i=x; i<=y; i++) cout<<pref[i]<<" "; cout<<endl;
    // for (ll i=x; i<=y; i++) cout<<suff[i]<<" "; cout<<endl<<endl;
    return (suff[x]+1)/2;
}

void solve()
{
    cin>>n;
    cin>>s; s=" "+s;
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=i; j<=n; j++)
            ans+=f(i, j);
    cout<<ans<<endl;
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