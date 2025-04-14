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

void solve()
{
    ll n; cin>>n; 
    ll a[n+5], ans=0;
    vector<ll> lis;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) 
    {
        ll p=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();  // cout<<p<<endl;
        if (p==lis.size()) lis.push_back(a[i]);
        else lis[p]=a[i];
        // for (auto it: lis) cout<<it<<" "; cout<<endl;
    }
    cout<<(ll)lis.size();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}