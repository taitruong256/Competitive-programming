/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    map<string, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        char c; cin>>c;
        string t; cin>>t;
        if (c=='+')
        {
            for (ll i=0; i<t.size(); i++) t[i]=(t[i]-'0')%2+'0';
            while (t.size()<18) t='0'+t;
            ++cnt[t];
        }
        else if (c=='-')
        {
            for (ll i=0; i<t.size(); i++) t[i]=(t[i]-'0')%2+'0';
            while (t.size()<18) t='0'+t;
            --cnt[t];
        } 
        else 
        {
            while (t.size()<18) t='0'+t;
            cout<<cnt[t]<<endl; 
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