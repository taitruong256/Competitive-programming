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
    string s; cin>>s;
    ll n=s.size();
    s="#"+s+"#";;
    ll f[n+5];
    memset(f, 0, sizeof(f));
    string t="";
    for (ll i=1; i<=n; i++) 
        if (s[i]!=s[i+1]) t=t+s[i];
        else i++;
    //cout<<t<<endl;

    map<char, vector<ll>> mp;
    t=" "+t;
    for (ll i=1; i<=t.size()-1; i++) 
    {
        mp[t[i]].push_back(i);
        if (mp[t[i]].size()==1) f[i]=f[i-1]+1;
        else 
        {
            vector<ll> v=mp[t[i]];
            ll a=v[v.size()-1];
            ll b=v[v.size()-2];
            f[i]=min(a-b-1+f[b-1], f[-1]+1);
        }
    }
    // for (auto c: mp)
    // {
    //     cout<<c.first<<" ";
    //     for (auto i: c.second) cout<<i<<" ";
    //     cout<<endl;

    // }
    //for (ll i=1; i<=t.size()-1; i++) cout<<f[i]<<" "; cout<<endl;
    if ((n-f[t.size()-1])%2==1) f[t.size()-1]++;
    cout<<f[t.size()-1]<<endl;
    
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