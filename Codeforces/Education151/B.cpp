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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

ll phia(pair<ll, ll> a, pair<ll, ll> c)
{
    if (a.first<=c.first && a.second>c.second) return 0;
    if (a.first>c.first && a.second>=c.second) return 1;
    if (a.first>=c.first && a.second<c.second) return 2;
    if (a.first<c.first && a.second<=c.second) return 3;
    assert(1>2);
}

void solve()
{
    pair<ll, ll> p[5];
    for (ll i=1; i<=3; i++) cin>>p[i].first>>p[i].second;
    ll a=phia(p[2], p[1]);
    ll b=phia(p[3], p[1]);  
    if ((a+2)%4==b)
    {
        cout<<1<<endl;
        return;
    }
    else if (a==b)
    {
        ll x, y;
        if (a==0)
        {
            x=max(p[2].first, p[3].first);
            y=min(p[2].second, p[3].second);
        }
        if (a==1)
        {
            x=min(p[2].first, p[3].first);
            y=min(p[2].second, p[3].second);
        }
        if (a==2)
        {
            x=min(p[2].first, p[3].first);
            y=max(p[2].second, p[3].second);
        }
        if (a==3)
        {
            x=max(p[2].first, p[3].first);
            y=max(p[2].second, p[3].second);
        }
        cout<<dist({x, y}, p[1])+1<<endl;
    }
    else 
    {
        if (a>b) swap(a, b);
        if (a==0)
        {
            if (b==1) cout<<abs(min(p[2].second, p[3].second)-p[1].second)+1<<endl;
            else cout<<abs(max(p[2].first, p[3].first)-p[1].first)+1<<endl;
        }
        else if (a==1)
        {
            cout<<abs(min(p[2].first, p[3].first)-p[1].first)+1<<endl;
        }
        else 
        {
            cout<<abs(max(p[2].second, p[3].second)-p[1].second)+1<<endl;
        }
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}