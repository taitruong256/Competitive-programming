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
    map<string, ll> count;
    ll n; cin>>n;
    while (n--)
    {
        char c; string s; cin>>c>>s;
        for (ll i=0; i<s.size(); i++) s[i]=(s[i]-'0')%2+'0';
        while (s.size()<18) s='0'+s; 
        if (c=='+') count[s]++;
        else if (c=='-') count[s]--;
        else cout<<count[s]<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;       // cin>>t;
    while (t--) solve();
    return 0;
}