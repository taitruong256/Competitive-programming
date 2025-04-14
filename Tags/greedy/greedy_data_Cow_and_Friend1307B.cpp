/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x, m=0; cin>>n>>x;
    ll a[n+5];
    set<ll> st;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
        m=max(m, a[i]);
    }
    if (st.count(x))
    {
        cout<<1<<endl;
        return;
    }
    cout<<max(2LL, (x+m-1)/m)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}