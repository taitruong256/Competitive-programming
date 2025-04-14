/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5], mn=1e10;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
        mn=min(mn, a[i]);
    }
    sort(b+1, b+n+1);
    bool check=true;
    for (ll i=1; i<=n; i++) if (a[i]!=b[i] && a[i]%mn!=0) check=false;
    if (check) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}