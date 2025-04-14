/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;

    vector<ll> pos[26];
    for (ll i=0; i<s.size(); i++) pos[s[i]-'a'].push_back(i+1);

    ll m; cin>>m;
    for (ll i=0; i<m; i++)
    {
        string t; cin >> t;
        vector<ll> cnt(26);
        for (ll j=0; j<t.size(); j++) ++cnt[t[j] - 'a'];
        ll ans =0;
        for(ll j=0; j<26; j++) if (cnt[j] > 0)
            ans = max(ans, pos[j][cnt[j] - 1]);
        cout<<ans<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}