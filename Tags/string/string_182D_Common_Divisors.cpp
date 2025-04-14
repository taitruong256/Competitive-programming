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
    string s, t; cin>>s>>t;
    if (s.size()>t.size()) swap(s, t);
    ll n=s.size(), ans=0;
    for (ll i=1; i<=n; i++) if (s.size()%i==0 && t.size()%i==0)
    {
        set<string> st;
        for (ll j=0; j<s.size(); j+=i) st.insert(s.substr(j, i));
        for (ll j=0; j<t.size(); j+=i) st.insert(t.substr(j, i));
        if (st.size()==1) ++ans;
    }
    cout<<ans;
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