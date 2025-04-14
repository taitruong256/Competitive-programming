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
    ll n, ans=0; cin>>n;
    map<ll, ll> mp1, mp2;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        mp1[x]=i;
    }
    for (ll i=1; i<=n; i++)

    {
        ll x; cin>>x;
        ll diff=mp1[x]-i;
        if (diff<0) diff+=n;
        mp2[diff]++;
        ans=max(ans, mp2[diff]);
    }
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}