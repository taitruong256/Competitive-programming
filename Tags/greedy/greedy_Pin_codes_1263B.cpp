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
    ll n; cin>>n;
    string a[n+5];
    set<char> st[5];
    map<string, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        a[i]=s;
        ++cnt[s];
        for (ll j=0; j<4; j++) st[j].insert(s[j]);
    }
    
    ll ans=0;
    for (ll i=0; i<n; i++) if (cnt[a[i]]>1)
    {
        for (ll j=0; j<4; j++)
        {
            bool ok=false;
            for (char c='0'; c<='9'; c++) if (st[j].count(c)==0)
            {           
                --cnt[a[i]];               
                a[i][j]=c;
                st[j].insert(c);
                ++ans;
                ok=true;    
                break;
            }
            if (ok) break;
        }
    }

    cout<<ans<<endl;
    for (ll i=0; i<n; i++) cout<<a[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}