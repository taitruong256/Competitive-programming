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
map<char, vector<ll>> index;

void solve()
{
    string s1, s2; cin>>s1>>s2;
    for (ll i=0; i<s1.size(); i++) index[s1[i]].push_back(i);
    ll truoc=-1, ans=1;
    for (auto c: s2)
    {    
        if (index[c].size()==0)
        {
            cout<<-1;
            return;
        }
        if (upper_bound(index[c].begin(), index[c].end(), truoc)==index[c].end()) ++ans, truoc=-1;
        truoc=upper_bound(index[c].begin(), index[c].end(), truoc)-index[c].begin();
        truoc=index[c][truoc];

        //cout<<c<<" "<<ans<<" "<<truoc<<endl;
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