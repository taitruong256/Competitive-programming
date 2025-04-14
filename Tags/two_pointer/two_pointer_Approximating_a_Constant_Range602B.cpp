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
    ll n; cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    multiset<ll> ms;
    ll j=0, ans=0;
    for (int i=0; i<n; i++)
    {
        ms.insert(a[i]);
        while (j<n && *(--ms.end())-*(ms.begin())>1)
        {
            ms.erase(ms.find(a[j]));
            ++j;
        }
        ans=max(ans, i-j+1);
    }
    cout<<ans;
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