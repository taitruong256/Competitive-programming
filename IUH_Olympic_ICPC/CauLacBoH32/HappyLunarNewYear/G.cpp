/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    string s="";
    string a[n+5];
    ll x[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) cin>>x[i];

    for (ll i=0; i<n; i++)
        for (ll j=0; j<x[i]; j++) s+=a[i];

    sort(s.begin(), s.end());         //cout<<s<<endl;
    ll sz=s.size();
    if (sz%2==0) cout<<s[sz/2-1]<<" "<<s[sz/2];
    else cout<<s[sz/2-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_+1<<endl;
        solve();
    }
    return 0;
}

//taitruong256