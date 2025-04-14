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
    ll n; cin>>n;
    string s, t, s1, t1; cin>>s>>t;
    vector<ll> vs, vt;
    for (ll i=0; i<n; i++) if (s[i]!='b')
    {
        s1+=s[i];
        vs.push_back(i);
    }
    for (ll i=0; i<n; i++) if (t[i]!='b')
    {
        t1+=t[i];
        vt.push_back(i);
    }

    if (s1!=t1)
    {
        cout<<"NO\n";
        return;
    }                
    for (ll i=0; i<vt.size(); i++)
    {
        if (s1[i]=='a' && vs[i]>vt[i])
        {
            cout<<"NO\n";
            return;
        }
        if (s1[i]=='c' && vs[i]<vt[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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