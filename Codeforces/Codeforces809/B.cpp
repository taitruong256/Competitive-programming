/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n; cin>>n;  // cout<<n<<endl;
    map<ll, vector<ll>> index;
    ll a[n+5];
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        index[a[i]].push_back(i);
    }
    for (ll i=1; i<=n; i++)
    {
        ll ans=0;
        if (index[i].size()!=0)
        {
            ans=1;
            for (ll j=1; j<index[i].size(); j++) if ((index[i][j]-index[i][j-1])%2==1) ++ans;
        } 
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}