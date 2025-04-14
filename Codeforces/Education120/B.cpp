#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double;
#define pb push_back
#define mp make_pair
#define endl "\n"
const ll mod = 1e9+7;
const ll inf = 1e9;
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
 
void solve()
{
    ll n; cin>>n;
    vector<pair<ll, ll>> a, ans(n), like, not_like;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        a.push_back(make_pair(x, i));
    }
    string s; cin>>s;
    for (int i=0; i<s.size(); i++) if (s[i]=='1') like.pb(mp(a[i].first, a[i].second));
    for (int i=0; i<s.size(); i++) if (s[i]=='0') not_like.pb(mp(a[i].first, a[i].second));

    // for (auto i: like) cout<<i.first<<" ";
    // for (auto i: not_like) cout<<i.first<<" "; cout<<endl;

    sort(like.rbegin(), like.rend());
    sort(not_like.rbegin(), not_like.rend());
    ll t=n;
    for (auto i: like) 
    {
       ans[i.second].first=t;
       --t;
    }
    for (auto i: not_like) 
    {
       ans[i.second].first=t;
       --t;
    }
    for(auto i: ans) cout<<i.first<<" ";
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
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}