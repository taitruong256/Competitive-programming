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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    vector<ll> ans(n, 0);
    for (ll i=0; i<n; i++) if (s[i]=='0' && k>0) 
    {
        s[i]='1';
        --k;
        ++ans[i];
    }
    ans[n-1]+=k;
    if (k%2==1) s[n-1]='0'+1-(s[n-1]-'0'); 
    cout<<s<<endl;
    for (auto it: ans) cout<<it<<" "; cout<<endl;
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