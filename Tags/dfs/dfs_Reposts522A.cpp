/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
map<string, vector<string>> mp;

void dfs(string s, ll cnt)
{
    ans=max(ans, cnt);  
    for (auto it: mp[s]) dfs(it, cnt+1);  
}

void solve()
{
    ll n; cin>>n;
    
    for (ll i=0; i<n; i++)
    {
        string a, b, c; cin>>a>>b>>c;
        for (int i=0; i<a.size(); i++) a[i]=toupper(a[i]);
        for (int i=0; i<c.size(); i++) c[i]=toupper(c[i]);
        mp[c].push_back(a);
    }
    
    // for (auto i: mp)
    // {
    //     cout<<i.first<<"  |  ";
    //     for (auto j: i.second) cout<<j<<" ";
    //     cout<<endl;
    // }

    for (auto it: mp) dfs(it.first, 1);     
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
