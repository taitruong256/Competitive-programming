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
    map<ll, ll> mp;
    for (ll i=0; i<n; i++)
    {
        mp[a[i]]++;
        if (mp[a[i]]>1) mp[-a[i]]++;
    }
    cout<<mp.size()<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                 cin>>t;
    while (t--) solve();
    return 0;
}