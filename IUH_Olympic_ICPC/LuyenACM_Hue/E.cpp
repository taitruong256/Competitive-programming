/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], sum=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll f[sum+5];
    memset(f, 0, sizeof(f));
    f[0]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=sum; j>=a[i]; j--) if (f[j-a[i]]==1 && f[j]==0) f[j]=1;
    
    vector<ll> v;
    for (ll i=1; i<=sum; i++) if (f[i]==1) v.push_back(i);
    cout<<v.size()<<endl;
    for (auto i: v) cout<<i<<" ";
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