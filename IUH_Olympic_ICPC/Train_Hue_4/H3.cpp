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
    map<string, string> mp1;
    map<string, vector<string>> mp2;

    for (ll i=0; i<n; i++)
    {
        string s, t; cin>>s>>t;
        mp1[s]=t;
        mp2[t].push_back(s);
    }

    ll ans=0;
    for (auto i: mp1)
    {  
        for (ll j=1; j<=i.first.size(); j++) if (mp2.count(i.first.substr(0, j))>0)
        {
            for (auto k: mp2[i.first.substr(0, j)]) if (i.second==k.substr(0, i.second.size())) ++ans;
            //cout<<i.first.substr(0, j)<<endl;
        }
    }
   
    cout<<ans/2;
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