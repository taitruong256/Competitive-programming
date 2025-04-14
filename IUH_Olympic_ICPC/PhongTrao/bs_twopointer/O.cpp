/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tinh(ll n, multiset<ll> ms)
{
    ll cnt=0;
    while (ms.size()>=2)
    {
        ll it=*ms.begin();
        if (it!=n-it && ms.find(n-it)!=ms.end())
        {
            ++cnt; 
            ms.erase(ms.find(it));
            ms.erase(ms.find(n-it));
        }
        else if (it==n-it && ms.count(it)>=2)
        {
            ++cnt; 
            ms.erase(ms.find(it));
            ms.erase(ms.find(it));
        }
        else ms.erase(ms.find(it));
    }
    return cnt; 
}

void solve()
{
    ll n; cin>>n;
    multiset<ll> ms;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ms.insert(x);
    }

    ll ans=0;
    for (ll i=1; i<=2*n; i++) 
    {
        // for (auto it: ms) cout<<it<<" "; cout<<endl;
        ans=max(ans, tinh(i, ms));   //      cout<<tinh(i, ms)<<endl;
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