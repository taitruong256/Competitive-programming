/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;

void solve()
{
    string s; cin>>s;
    s=" "+s;
    for (auto c: s) if (c=='w' || c=='m')
    {
        cout<<0;
        return;
    }

    ll f[s.size()+5];
    f[0]=1;
    f[1]=1;
    for (ll i=2; i<=s.size(); i++)
        if (s[i]==s[i-1] && (s[i]=='u' || s[i]=='n'))
            f[i]=(f[i-1]+f[i-2])%mod;
            else f[i]=f[i-1];
    cout<<f[s.size()];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}