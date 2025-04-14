/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    string s; cin>>s;
    ll ans=0, res=0;
    string t="";
    for (ll i=0; i<s.size(); i+=2)
    {
        if (s[i]!=s[i+1]) ++ans;
        if (s[i]==s[i+1]) t=t+s[i]+s[i+1];
    }             
    t=t+"$"; cout<<t<<endl;
    if (t=="$") res=1;
    else for (ll i=0; i<t.size()-1; i++) if (t[i]!=t[i+1]) ++res;
    cout<<ans<<" "<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}