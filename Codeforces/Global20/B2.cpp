/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    string s; cin>>s;
    if (s.size()==1)
    {
        cout<<"NO\n";
        return;
    }
    ll cnt=0;
    for (ll i=0; i<s.size(); i++) if (s[i]=='A') ++cnt;
    if (cnt==s.size())
    {
        cout<<"NO\n";
        return;
    }
    ll a=0, b=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]=='A') ++a;
        else ++b;
        if (b>a)
        {
            cout<<"NO\n";
            return;
        }
    }
    if (s[s.size()-1]=='A')
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}