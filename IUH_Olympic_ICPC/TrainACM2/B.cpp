/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    map<string, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        cnt[s]++;
        if (cnt[s]==1) cout<<"OK\n";
        else cout<<s+to_string(cnt[s]-1)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}