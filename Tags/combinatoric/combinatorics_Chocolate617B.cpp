/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    vector<ll> pos;
    for(ll i=0; i<n; i++)
    {
        ll x; cin>>x;  
        if (x==1) pos.push_back(i);
    }
    ll ans=1;
    if (pos.size()==0)
    {
        cout<<0<<endl;
        return;
    }
    else if (pos.size()==1)
    {
        cout<<1<<endl;
        return;
    }
    for (ll i=1; i<pos.size(); i++) ans*=pos[i]-pos[i-1];
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}