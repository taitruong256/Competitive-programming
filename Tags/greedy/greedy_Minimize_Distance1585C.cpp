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
    vector<ll> pos, neg;
    neg.push_back(0);
    pos.push_back(0);
    for (ll i=0; i<n; i++)
    {
        if (a[i]>0) pos.push_back(a[i]);
        else neg.push_back(-a[i]);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll ans=0;
    for (ll i=pos.size()-1; i>=0; i-=k) ans+=2*pos[i];
    for (ll i=neg.size()-1; i>=0; i-=k) ans+=2*neg[i];
    ans-=max(pos[pos.size()-1], neg[neg.size()-1]);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}