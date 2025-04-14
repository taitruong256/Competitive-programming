/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s; cin>>s;
    bool used[s.size()+5];
    memset(used, false, sizeof(used));
    ll ans=0;
    for (ll i=1; i<s.size(); i++)
    {
        if (s[i]==s[i-1] && used[i-1]==false)
            used[i]=true;
        if (i>1 && s[i]==s[i-2] && used[i-2]==false)
            used[i]=true;
        ans+=used[i];
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}