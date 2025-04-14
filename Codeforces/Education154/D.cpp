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
    ll n, ans=0; cin>>n;
    vector<ll> a, b(n+5);
    for (ll i=1; i<=n; i++) cin>>b[i];
    a.push_back(mod);
    a.push_back(b[1]);
    for (ll i=2; i<=n; i++) 
        if (b[i]==b[i-1]) ++ans;
        else a.push_back(b[i]);
    a.push_back(mod);
    // for (auto i: a) cout<<i<<" "; cout<<endl;




    vector<ll> v;
    ll r=1, pre=-1e9;
    n=a.size()-2;
    for (ll l=1; l<=n; l++)
    {
        if (a[l]<a[l+1]) 
        {
            r=l;
            while (r<=n && a[r]<a[r+1]) ++r;
            v.push_back(a[l]);
        }
        if (a[l]>a[l+1])
        {
            ++ans;
            r=l;
            while (r<=n && a[r]>a[r+1]) ++r;
            v.push_back(++pre);
        }
        l=r;
    }
    // cout<<ans<<endl;
    // for (auto i: v) cout<<i<<" "; cout<<endl;
    for (ll i=1; i<v.size(); i++) if (v[i-1]>=v[i]) ++ans;
    cout<<ans<<endl;
    // cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}