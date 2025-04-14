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
    ll n; cin>>n;
    vector<string> captain, child, woman, man;
    for (ll i=0; i<n; i++)
    {
        string s, t; cin>>s>>t;
        if (t=="captain") captain.push_back(s);
        else if (t=="child") child.push_back(s);
        else if (t=="woman") woman.push_back(s);
        else man.push_back(s);
    }

    for (auto s: captain) cout<<s<<endl;
    for (auto s: child) cout<<s<<endl;
    for (auto s: woman) cout<<s<<endl;
    for (auto s: man) cout<<s<<endl;
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