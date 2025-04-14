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
    string n; cin>>n;
    reverse(n.begin(), n.end());
    while (n[0]=='0') n.erase(0, 1);
    ll x=0;
    for (ll i=0; i<n.size(); i++) x=x*10+(n[i]-'0');
    cout<<x<<" ";
    ll t=(ll)sqrt(x);
    if (t*t==x) cout<<"YES"; else cout<<"NO";
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