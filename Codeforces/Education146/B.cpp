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

void solve()
{
    ll x, y; cin>>x>>y;
    if (x>y) swap(x, y);
    ll ans=x+y;
    for (ll i=1; i*i<=y; i++)
    {
        ll res=0, t=i;
        res+=y/t;
        if (y%t==0)
        {
            if (x%t==0) res+=x/t+t-1;
            else res+=x/t+t;
        }
        else 
        {
            ll d=y%t;
            res+=1;
            res+=x/d;
            res+=d;
        }
        ans=min(ans, res);               cout<<t<<" "<<res<<endl;

        res=0, t=y/i;
        res+=y/t;
        if (y%t==0)
        {
            if (x%t==0) res+=x/t+t-1;
            else res+=x/t+x%t;
        }
        else 
        {
            ll d=y%t;
            res+=1;
            res+=x/d;
            res+=d;
        }
        ans=min(ans, res);                 cout<<t<<" "<<res<<endl;
    }
    cout<<ans<<endl;
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