#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
void solve()
{  
    ll n, m; cin>>n>>m;
    ll c[n+1], t[n+1];
    for (ll i=1; i<=n; i++) cin>>c[i]>>t[i];
    ll s[n+1];
    s[0]=0;
    for (ll i=1; i<=n; i++) s[i]=s[i-1]+c[i]*t[i];

    ll j=0;
    for (ll i=1; i<=m; i++)
    {
        ll v; cin>>v;
        while (s[j]<v) ++j;
        cout<<j<<endl;
    }
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