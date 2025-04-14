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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
ll n, q, a[200005], le[200005], ri[200005], ans[200005];
pair<ll, ll> qry[200005];

void divide_and_conquer(ll l, ll r, vector<ll> idx)
{
    if (idx.size()==0) return;
    if (l==r)
    {
        for (ll i: idx) ans[i]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    le[mid]=a[mid];
    for (ll i=mid-1; i>=1; i--) le[i]=min(a[i], le[i+1]);
    ri[mid+1]=a[mid+1];
    for (ll i=mid+2; i<=n; i++) ri[i]=min(a[i], ri[i-1]);
    vector<ll> todo[2];
    for (ll i: idx)
    {
        auto [lt, rg]=qry[i];  
        if (rg==mid)
        {
            ans[i]=le[lt];
            continue;
        }
        if (lt<=mid && mid<rg) 
        {
            ans[i]=min(le[lt], ri[rg]);
            continue;
        }
        todo[lt>mid].push_back(i);
    }
    divide_and_conquer(l, mid, todo[0]);
    divide_and_conquer(mid+1, r, todo[1]);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=q; i++) cin>>qry[i].first>>qry[i].second;
    vector<ll> idx;
    for (ll i=1; i<=q; i++) idx.push_back(i);
    divide_and_conquer(1, n, idx);
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
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