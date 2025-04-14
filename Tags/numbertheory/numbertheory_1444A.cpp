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
    ll p, q;cin>>p>>q;
    set<ll> st;
    ll x=q;
    for (ll i=2; i*i<=x; i++) if (x%i==0)
    {
        while (x%i==0) x/=i, st.insert(i);
    }
    if (x>1) st.insert(x);
    
    ll ans=1;
    for (auto it: st)
    {
        ll x=p;
        while (x%q==0) x/=it;
        ans=max(ans, x);
    }
    cout<<ans<<endl;
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