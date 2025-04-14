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
    string s ;cin>>s;
    string t[]={"twone", "one", "two"};
    vector<ll> ans;
    for (auto x: t) 
    {
        ll pos=0;
        pos=s.find(x, pos);
        while (pos<s.size()) 
        {    
            s[pos+x.size()/2]='?';         // cout<<s<<endl;
            ans.push_back(pos+x.size()/2+1);
            pos=s.find(x, pos);
        }
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}