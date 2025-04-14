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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    for (ll i=n-1; i>=0; i--) if (k>0 && s[i]=='1' && s[i+1]=='0') 
    {
        swap(s[i], s[i+1]);
        --i;
    }
    ll ans=0;
    for (ll i=0; i<n-1; i++)
    {
        ll x=(s[i]-'0')*10+(s[i+1]-'0');
        ans+=x;
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
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}