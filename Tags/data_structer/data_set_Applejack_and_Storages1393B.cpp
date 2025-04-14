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
    map<ll, ll> d1, d2;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        d1[x]++;
        d2[d1[x]]++;
    }

    ll q; cin>>q;
    for (ll i=0; i<q; i++) 
    {
        char c; ll x; cin>>c>>x;
        if (c=='+') 
        {
            ++d1[x];
            ++d2[d1[x]];
        }
        else 
        {
            --d2[d1[x]];
            --d1[x];
        }    // for (auto it: d2) cout<<it.first<<" "<<it.second<<"  |  "; cout<<endl;
        if(d2[8]>0||(d2[4]>=2)||(d2[6]>0&&d2[2]>=2)||(d2[4]>0&&d2[2]>=3))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                // cin>>t;
    while (t--) solve();
    return 0;
}