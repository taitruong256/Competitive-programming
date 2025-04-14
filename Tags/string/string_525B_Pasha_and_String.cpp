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
    int n=s.size();
    int m; cin>>m;
    ll d[n+5];
    memset(d, 0, sizeof(d));
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        d[x]++;
    }
    for (ll i=1; i<=n/2; i++) d[i]+=d[i-1];
    for (ll i=0; i<=n/2; i++) if (d[i]%2==1) swap(s[i-1], s[n-i]);
    cout<<s<<endl;
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