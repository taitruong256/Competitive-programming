#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    ll n; cin>>n;
    map<string, string> old;
    for (ll i=1; i<=n; i++)
    {
        string s, t; cin>>s>>t;
        if (old[s]!="") old[t]=old[s];
        else old[t]=s;
        old.erase(s);
    } 
    cout<<old.size()<<"\n";
    for(auto x:old) cout<<x.second<<" "<<x.first<<"\n";
}
 
int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}