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
    ll n, k; cin>>n>>k;
    set<ll> st;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        st.insert(x);
    }
    if (st.size()>k) 
    {
        cout<<-1<<endl;
        return;
    }
    for (ll i=1; st.size()<k; i++) st.insert(i);
    cout<<n*k<<endl;
    for (ll i=0; i<n; i++)
        for (auto it: st) cout<<it<<" ";
    cout<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}