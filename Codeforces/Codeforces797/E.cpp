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

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5], ans=0;
    multiset<ll> st;
    for (ll i=1; i<=n; i++) 
    {               
        cin>>a[i];
        ans+=a[i]/k;
        st.insert(a[i]%k);
    }

    while (!st.empty())
    {
        ll x=*st.begin();
        st.erase(st.find(x));
        auto it=st.lower_bound(k-x);
        if (it!=st.end())
        {
            st.erase(st.find(*it));
            ++ans;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}