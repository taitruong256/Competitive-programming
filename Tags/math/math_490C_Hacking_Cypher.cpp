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
const ll mod = 1e9+7;
ll pref[1000005], suff[1000005];

void solve()
{
    string s; cin>>s; s=" "+s;
    ll a, b; cin>>a>>b;
    ll n=s.size()-1;
    for (ll i=1; i<=n; i++) pref[i]=(pref[i-1]*10+s[i]-'0')%a;
    ll p=1;
    for (ll i=n; i>=1; i--)
    {
        suff[i]=((s[i]-'0')*p+suff[i+1])%b;
        p=(p*10)%b;
    }
    for (ll i=1; i<=n-1; i++) if (pref[i]==0 && suff[i+1]==0 && s[i+1]!='0')
    {
        cout<<"YES\n";
        cout<<s.substr(1, i)<<endl;
        cout<<s.substr(i+1, n-i+1);
        return;
    }
    cout<<"NO";
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