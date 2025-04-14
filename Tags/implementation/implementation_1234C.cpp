/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s[2];
    ll n; cin>>n;
    cin>>s[0]>>s[1];   //cout<<n<<" "<<s[0]<<" "<<s[1]<<endl;
    ll row=0;
    for (ll i=0; i<n; i++) if (s[row][i]>='3')
    {
        if (s[row^1][i]<'3')
        {
            cout<<"NO\n";
            return;
        }
        row^=1;
    }
    if (row==1) cout<<"YES\n";
    else cout<<"NO\n";
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