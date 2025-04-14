/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll k, a, b; cin>>k>>a>>b;
    string s; cin>>s;       
    if (s.size()<a*k || s.size()>b*k) 
    {
        cout<<"No solution";
        return;
    }
    
    ll n=s.size();
    ll m=n%k;
    ll d=0;
    for (ll i=0; i<n; i++)
    {
        ++d;
        if (d<=k-n%k)
        {
            ll j;
            for (j=i; j<i+n/k; j++) cout<<s[j];
            cout<<endl;
            i=j-1;
        }
        else
        {
            ll j;
            for (j=i; j<i+n/k+1; j++) cout<<s[j];
            cout<<endl;
            i=j-1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}