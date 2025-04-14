/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s, t; cin>>s>>t;
    map<char, vector<ll>> mp;
    map<char, ll> cnt; 
    for (auto c: s) ++cnt[c];
    for (auto c: t) if (cnt[c]==0)
    {
        cout<<-1<<endl;
        return;
    }
    for (ll i=0; i<s.size(); i++) mp[s[i]].push_back(i);

    // for (auto it: mp)
    // {
    //     cout<<it.first<<" ";
    //     for (auto j: it.second) cout<<j<<" ";
    //     cout<<endl;
    // }
    ll ans=0, i=0;
    while (i<t.size())
    {
        ll index=0;
        bool check=1;
        while (i<t.size() && check==1)
        {
            ll pos=lower_bound(mp[t[i]].begin(), mp[t[i]].end(), index)-mp[t[i]].begin();
            // cout<<i<<" "<<pos<<" "<<ans<<" "<<check<<endl;
            if (pos>=mp[t[i]].size())
            {
                ++ans;
                check=0;
            }
            if (check==1)
            {
                index=mp[t[i]][pos]+1;
                i++;
            }
            
        }
    }
    cout<<ans+1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}