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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll mn=*min_element(a+1, a+n+1), mx=*max_element(a+1, a+n+1);
    if (mn==mx)
    {
        cout<<0;
        return;
    }
    
    ll vmax=1, vmin=1;
    for (ll i=1; i<=n; i++) if (a[i]==mx)
    {
        vmax=i;
        break;
    }
    for (ll i=n; i>=1; i--) if (a[i]==mn) 
    {
        vmin=i;
        break; 
    }
    if (vmax<vmin) cout<<vmax-1+n-vmin;
    else cout<<vmax-1+n-vmin-1;
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