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
    ll n; cin>>n;
    string s; cin>>s;
    s="W"+s+"W";
    ll red=0, blue=0;
    ll white=0;
    for (ll i=1; i<=n+1; i++) if (s[i]!='W')
    {
        ll j=i;
        while (s[j]!='W')
        {
            if (s[j]=='B') ++blue;
            else if (s[j]=='R') ++red;
            ++j;
        }
        if (red==0 || blue==0)
        {
            cout<<"NO\n";
            return;
        }
        red=0;
        blue=0;
        i=j-1;
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}