#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n; cin>>n;
    ll a[200005], last[200005];
    memset(last, -1, sizeof(last));
    for (ll i=0; i<n; i++) cin>>a[i];
    ll ans=1000000005;
    for (int i=0; i<n; i++)
    {
        if (last[a[i]]!=-1) ans=min(ans, i-last[a[i]]+1);
        last[a[i]]=i;
    }
    if (ans==1000000005) ans=-1;
    cout<<ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
