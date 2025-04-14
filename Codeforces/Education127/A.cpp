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
    ll a=0, b=0;
    ll n=s.size();
    s="$"+s+"$";
    s[0]=s[1];
    for (ll i=1; i<=n+1; i++)
    {
        if (s[i]==s[i-1])
        {
            if (s[i]=='a') ++a;
            else ++b;
        }
        else 
        {
            if (a==0 && b==1)
            {
                cout<<"NO\n";
                return;
            }
            else if (b==0 && a==1)
            {
                cout<<"NO\n";
                return;
            }
            a=(s[i]=='a');
            b=(s[i]=='b');
        }
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