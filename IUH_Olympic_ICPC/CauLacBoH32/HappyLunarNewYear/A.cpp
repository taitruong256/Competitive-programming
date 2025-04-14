/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    map<ll, ll>   mp;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]]=  1;
    }

    ll ans=0;
    for (int i=0; i<n; i++) if (!(mp[a[i]-k]==0 && mp[a[i]+k]==0)) ++ans;
    ++ans;
    cout<<n-ans/2;
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
