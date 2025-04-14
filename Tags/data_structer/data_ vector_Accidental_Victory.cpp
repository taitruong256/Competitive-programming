#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/


void solve()
{               
    ll n; cin>>n;
    vector<pair<ll, ll>> v;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    ll sum=0, ind=0;
    for (ll i=0; i<v.size(); i++) 
        if (v[i].first<sum) 
        {
            ind=v[i].second;
        } 
        else sum+=v[i].first;
    cout<<ind<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}