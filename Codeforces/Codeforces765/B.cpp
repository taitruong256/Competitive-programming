/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first==b.first)
        return a.second<a.second;
    return a.first<b.first;
}

void solve()
{
    ll n; cin>>n;
    vector<pair<ll, ll>> a(n);
    for (ll i=0; i<n; i++) cin>>a[i].first;
    for (ll i=0; i<n; i++) a[i].second=i;
    sort(a.begin(), a.begin()+n, cmp);

    for (ll i=0; i<n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;   cout<<endl;
    ll ans=-1;
    for(ll i=0; i<n; i++)
    {
        pair<ll, ll> l, r;
        l=a[i];
        ll j;
        for (j=i; j<n; j++) 
        {
            if (a[j].first!=a[i].first) break;
            r=a[j];
        }  cout<<l.first<<" "<<l.second<<"          "<<r.first<<" "<<r.second<<endl;
        ans=max(ans, max(l.second, n-r.second));
        i=j-1;
    }
    cout<<ans<<endl<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}
