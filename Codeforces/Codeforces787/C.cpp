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
    if (s.size()==1)
    {
        cout<<1<<endl;
        return;
    }
    ll ans=0, pos=0, cnt=0;
    for (ll i=s.size()-1; i>=0; i--)
    {
        if (s[i]=='1') ++cnt;
        if (cnt==2)
        {
            pos=i;
            break;
        }
    }   
    ans=1;
    for (ll i=pos+1; i<s.size(); i++) if (s[i]=='?') ++ans;
    cout<<ans<<endl;
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