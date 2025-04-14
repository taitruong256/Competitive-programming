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

ll n;
string s; 
ll pref[200005][30], suff[200005][30];

void solve()
{
    cin>>n;
    cin>>s; s=" "+s;
    
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<26; j++)
            if (i==1)
                pref[i][j]=(s[i]-'a'==j);
            else 
                pref[i][j]=pref[i-2][j]+(s[i]-'a'==j);

    for (ll i=n; i>=1; i--)
        for (ll j=0; j<26; j++) 
            if (i==n)
                suff[i][j]=(s[i]-'a'==j);
            else
                suff[i][j]=suff[i+2][j]+(s[i]-'a'==j); 

    if (n%2==0)
    {
        ll mx1=0, mx2=0;
        for (ll j=0; j<26; j++) 
        {
            mx1=max(mx1, pref[n-1][j]);
            mx2=max(mx2, pref[n][j]);
        }
        cout<<n-mx1-mx2<<endl;
    }    
    else 
    {
        ll ans=1e18;
        for (ll i=1; i<=n; i++)
        {
            ll mx1=0, mx2=0;
            for (ll j=0; j<26; j++) 
            {
                ll l1=0, l2=0, r1=0, r2=0;
                if (i>=1) l1=pref[i-1][j];
                if (i>=2) l2=pref[i-2][j];
                r1=suff[i+2][j];
                r2=suff[i+1][j];
                if (i%2==0)
                {
                    mx1=max(mx1, l1+r1);
                    mx2=max(mx2, l2+r2);
                }
                else 
                {
                    mx1=max(mx1, l2+r2);
                    mx2=max(mx2, l1+r1);
                }
            }
            ans=min(ans, n-mx1-mx2);
        }
        cout<<ans<<endl;
    }

    for (ll i=1; i<=n; i++)
        for (ll j=0; j<26; j++)
            pref[i][j]=suff[i][j]=0;
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