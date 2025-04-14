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

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
map<array<int, 5>, ll> cnt;

inline ll size(array<int, 5> v)
{
    ll sz=0;
    while (sz<5 && v[sz]!=0) ++sz;
    return sz;
}

void solve()
{
    setIO("cowpatibility");
    
    ll n, m; cin>>n;
    m=n;
    while (m--)
    {
        array<int, 5> v;
        for (ll i=0; i<5; i++) 
        {
            ll x; cin>>x;
            v[i]=x;
        }
        sort(v.begin(), v.end());
        for (ll i=1; i<(1LL<<5); i++)
        {
            ll id=0;
            array<int, 5> subset={0, 0, 0, 0, 0};
            for (ll j=0; j<5; j++) if (i&(1<<j)) subset[id++]=v[j];
            cnt[subset]++;
        }         
    }
    ll ans=0;
    for (auto [v, x]: cnt)
    {
        
        if (size(v)%2==1) ans+=x*(x-1)/2;
        else ans-=x*(x-1)/2;
    }
    cout<<n*(n-1)/2-ans;
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