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
vector<pair<int, char>> v;

void tinh(char c)
{
    if (c=='A') v[0]={v[0].first-1, v[0].second};
    if (c=='B') v[1]={v[1].first-1, v[1].second};
    if (c=='C') v[2]={v[2].first-1, v[2].second};
}

void solve()
{
    v.push_back({0, 'A'});
    v.push_back({0, 'B'});
    v.push_back({0, 'C'});
    for (ll i=0; i<3; i++)
    {
        string s; cin>>s;
        if (s[1]=='<') tinh(s[0]);
        else tinh(s[2]);
        // for (ll i=0; i<3; i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    sort(v.begin(), v.end());
    for (ll i=0; i<3; i++) if (v[i].first!=i-2)
    {
        cout<<"Impossible";
        return;
    }
    // for (ll i=0; i<3; i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    for (ll i=0; i<3; i++) cout<<v[i].second;
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