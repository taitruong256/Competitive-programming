#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void solve()
{
    ll r; cin>>r;
    vector<pair<ll, ll>> v;
    for (ll i=0; i<5; i++)
    {
        ll x, y; cin>>x>>y;
        v.push_back({x, y});
    }
    for (ll i=-1000; i<=1000; i++)
        for (ll j=-1000; j<=1000; j++)
        {
            bool check=true;
            for (auto [x, y]: v) 
            {
                if ((x-i)*(x-i)+(y-j)*(y-j)>r*r) check=false;
            }
            if (check==true)    
            {
                cout<<"YES\n";
                return;
            }
        }
    cout<<"NO\n";
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