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

void solve()
{
    ll n; cin>>n;
    ll a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    vector<ll> uoc;
    for (ll i=1; i*i<=n; i++) if (n%i==0)
    {
        uoc.push_back(i);
        if (i!=n/i) uoc.push_back(n/i);
    }
    sort(uoc.begin(), uoc.end());
    // for (auto i: uoc) cout<<i<<" "; cout<<endl;
    ll ans=0;
    for (ll k: uoc)
    {
        bool check=true;
        ll pre=-1, g=0;
        for (ll i=1; i<=k; i++)
        {
            pre=-1;
            for (ll j=i; j<=n; j+=k)
            {
                if (pre==-1) pre=a[j];
                else g=__gcd(g, abs(a[j]-pre)), pre=a[j];
                        //cout<<a[j]<<" ";
            }          //cout<<endl;
            if (g==1) check=false;
            // cout<<"---"<<i<<" "<<k<<" "<<g<<endl;
        }
        ans+=check;
        // if (check) cout<<"----"<<k<<endl;
    }
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