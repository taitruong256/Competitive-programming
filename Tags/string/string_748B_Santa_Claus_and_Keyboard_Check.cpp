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
    char x[300];
    memset(x, 0, sizeof(x));
    ll cnt=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (x[s[i]]==0 && x[t[i]]==0)
        {
            x[s[i]]=t[i];
            x[t[i]]=s[i];
        }
        else 
        {
            if (x[t[i]]!=0 && x[t[i]]!=s[i])
            {
                cout<<-1;
                return;
            }
            if (x[s[i]]!=0 && x[s[i]]!=t[i])
            {
                cout<<-1;
                return;
            }
        }
    }
    vector<pair<char, char>> ans;
    for (char c='a'; c<='z'; c++) if (x[c]<c && x[c]>0) ans.push_back({c, x[c]});
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
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