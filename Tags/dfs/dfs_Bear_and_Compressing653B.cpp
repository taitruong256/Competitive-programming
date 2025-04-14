/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans=0;
map<string, string> mp;

void dfs(string s)
{     
    if (s.size()<n)
        for (char c='a'; c<'a'+6; c++) dfs(s+c);
    else
    {     
        string t=s;  //cout<<t<<endl;
        for (ll i=0; i<n-1; i++) if (mp.count(t.substr(0, 2))) t=mp[t.substr(0, 2)]+t.substr(2);
        if (t=="a") ++ans;
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        string a, b; cin>>a>>b;
        mp[a]=b;
    }
    dfs("");
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
