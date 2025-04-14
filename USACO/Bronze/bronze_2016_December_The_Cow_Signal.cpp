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
#define cout_return(x) return void(cout<<(x)<<endl)
const ll inf = 1e18;
const ll mod = 1e9+7;

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    for (ll i=1; i<=n; i++)
    {
        string s, ans; cin>>s;
        if (s.back()=='.') s=s+"X "; 
        else s=s+". ";
        string t;
        for (ll i=0; i<m; i++)
        {
            t.push_back(s[i]);
            if (s[i]!=s[i+1])
            {
                for (ll j=0; j<k; j++) ans=ans+t;
                t.clear();
            }
        }
        for (ll i=0; i<k; i++) cout<<ans<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}