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
    string s; cin>>s;
    string x=s;
    bool ok=false;
    vector<ll> ans;

    //chuyen sang trang
    for (ll i=0; i<n-1; i++) if (s[i]=='B')
    {
        ans.push_back(i+1);
        s[i]='W';
        if (s[i+1]=='W') s[i+1]='B'; else s[i+1]='W';        
    }
    if (s[n-1]=='W') ok=true;
    if (ok)
    {
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" "; cout<<endl;
        return;
    }
                                                    
    //chuyen sang den
    ans.clear();
    s=x;
    for (ll i=0; i<n-1; i++) if (s[i]=='W')
    {
        ans.push_back(i+1);
        s[i]='B';
        if (s[i+1]=='W') s[i+1]='B'; else s[i+1]='W';                    
    }
    if (s[n-1]=='B') ok=true;
    if (ok)
    {
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" "; cout<<endl;
        return;
    }
    cout<<-1<<endl;
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