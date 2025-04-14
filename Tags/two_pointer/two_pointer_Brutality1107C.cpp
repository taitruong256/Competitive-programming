#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n];
    string s;
    for (ll i=0; i<n; i++) cin>>a[i];
    cin>>s;

    ll j=0, ans=0;
    for (ll i=0; i<n; i++) 
    {
        while (j<n && s[j]==s[i]) ++j;
        sort(a+i, a+j, greater<ll>());
        for (ll l=i; l<min(i+k, j); l++) ans+=a[l];
        i=j-1;
    }
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}