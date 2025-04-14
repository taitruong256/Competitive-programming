/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll a[n+5], s1[n+5], s2[n+5];
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    for (ll i=1; i<=n; i++) cin>>a[i];   
    for (ll i=1; i<=n; i++) s1[i]=s1[i-1]+a[i];
    sort(a+1, a+n+1);                     
    for (ll i=1; i<=n; i++) s2[i]=s2[i-1]+a[i];
    // for (ll i=1; i<=n; i++) cout<<s1[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<s2[i]<<" "; cout<<endl;

    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll x, l, r; cin>>x>>l>>r;
        if (x==1) cout<<s1[r]-s1[l-1]<<endl;
        else cout<<s2[r]-s2[l-1]<<endl;
    }
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