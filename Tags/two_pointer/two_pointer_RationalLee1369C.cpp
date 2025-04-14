#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n, k; cin>>n>>k; 
    vector<ll> a(n), w(k);
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<k; i++) cin>>w[i];
    sort(a.begin(), a.end());      
    sort(w.begin(), w.end(), greater<ll>());
    
    ll ans=0;
    while (w.size()>0 && w.back()==1) 
    {
        ans+=a.back()*2;
        a.pop_back();
        w.pop_back();
    }
    ll l=0;
    k=w.size();
    for (ll i=0; i<k; i++)
    {
        ans+=a[l];
        l+=w[i]-1;
    }
    ll r=a.size()-1;
    for (ll i=0; i<k; i++)
    {
        ans+=a[r];
        --r;
    }
    cout<<ans<<endl;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
