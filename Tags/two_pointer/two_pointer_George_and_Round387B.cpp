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
    ll a[n], b[m];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll j=0; j<m; j++) cin>>b[j];

    ll i=0, j=0, ans=0;
    while (i<n && j<m)
    {
        if (b[j]<a[i]) ++j;
        else
        {
            ++i;
            ++j;
            ++ans;
        }
    }
    cout<<n-ans;
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