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
struct query
{
    ll ac, pen, idx;
};

bool comp(query a, query b)
{
    if (a.ac!=b.ac) return a.ac>b.ac;
    if (a.pen!=b.pen) return a.pen<b.pen;
    return a.idx<b.idx;
}

void solve()
{   
    ll n, m, h; cin>>n>>m>>h;
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    vector<query> v;
    for (ll i=1; i<=n; i++)
    {
        sort(a[i]+1, a[i]+m+1);
        ll ac=0, pen=0, total=0;
        for (ll j=1; j<=m; j++)
        {
            if (total+a[i][j]<=h)
            {
                total+=a[i][j];
                ++ac;
                pen+=total;
            }
            else break;
        }
        v.push_back({ac, pen, i});
    }
    sort(v.begin(), v.end(), comp);
    for (ll i=0; i<n; i++) if (v[i].idx==1) 
    {
        cout<<i+1<<endl;
        return;
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