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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxn = 200005;
const ll mod = 1e9+7;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s; s=" "+s+"@";
    string t; cin>>t; t=" "+t+"$";
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    vector<ll> khac, giong;
    ll sum=0;
    for (ll i=1; i<=n+1; i++)
    {
        if (s[i]==t[i]) sum+=a[i];
        else 
        {
            if (sum!=0) giong.push_back(sum);
            sum=0;
        }
    }
    sum=0; s[n+1]='$';
    for (ll i=1; i<=n+1; i++)
    {
        if (s[i]!=t[i]) sum+=a[i];
        else 
        {
            if (sum!=0) khac.push_back(sum);
            sum=0;
        }
    }
    ll ans=0;
    for (auto i: khac) ans+=i;
    if (k>=khac.size()) 
    {
        cout<<ans;
        return;
    }
    else 
    {
        sort(giong.begin(), giong.end());
        for (ll i=0; i<khac.size()-k; i++) ans+=giong[i];
        cout<<ans;
    }
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