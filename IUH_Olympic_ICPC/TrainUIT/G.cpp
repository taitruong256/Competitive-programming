/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll n;
ll a[100005];
map<ll, ll> truoc, sau;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) if (truoc[a[i]]==0) truoc[a[i]]=i;
    for (ll i=n; i>=1; i--) if (sau[a[i]]==0) sau[a[i]]=n-i+1;
    ll q; cin>>q;
    ll x=0, y=0;
    while (q--)
    {
        ll t; cin>>t;
        x+=truoc[t];
        y+=sau[t];
        if (truoc[t]==0) x+=n;
        if (sau[t]==0) y+n;
    }
    cout<<x<<" "<<y;
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