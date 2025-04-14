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
    string s; cin>>s;
    set<pair< pair<ll, ll>, pair<ll, ll> >> vis;
    ll x=0, y=0, ans=0;
    for (ll i=0; i<s.size(); i++) 
    {
        ll xx=x, yy=y;
        if (s[i]=='S') ++y;
        else if (s[i]=='N') --y;
        else if (s[i]=='W') ++x;
        else --x;
 
        if ((ll)vis.count({{x, y}, {xx, yy}})==0 && (ll)vis.count({{xx, yy}, {x, y}})==0)
            ans+=5;
        else 
            ans++;
        vis.insert({{x, y}, {xx, yy}});
        vis.insert({{xx, yy}, {x, y}});
    }
    cout<<ans<<endl;
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