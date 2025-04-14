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
    string s; cin>>s;
    ll cnt[2]={0, 0};
    ll ans=0;
    for (ll i=0; i<s.size(); i++) ++cnt[s[i]-'0'];
    if (cnt[0]>cnt[1]) ans=cnt[1];
    else if (cnt[0]<cnt[1]) ans=cnt[0];
    else ans=cnt[0]-1;
    cout<<ans<<endl;
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