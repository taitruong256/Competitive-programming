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
    for (ll i=0; i<n; i++) cin>>a[i];
    vector<ll> d;
    for (ll i=0; i<n-1; i++) d.push_back(a[i]-a[i+1]);

    sort(d.begin(), d.end());
    ll ans=a[n-1]-a[0];
    for (ll i=0; i<k-1; i++) ans+=d[i];
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_+1<<endl;
        solve();
    }
    return 0;
}

//taitruong256