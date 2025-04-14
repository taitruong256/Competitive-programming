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
    string s; 
    vector<string> v(1);
    ll mx=0, d=0;
    while (getline(cin, s))
    {
        v.push_back(s);
        mx=max(mx, (ll)s.size());
    }
    for (int i=0; i<v.size(); i++)
    {
        ll cnt=mx-(ll)v[i].size();
        if (cnt%2==1)
        {
            v[i]='*'+string(cnt/2+d, ' ')+v[i]+string(cnt-cnt/2-d, ' ')+'*';
            d=1-d;
        }
        else
        {
            v[i]='*'+string(cnt/2, ' ')+v[i]+string(cnt-cnt/2, ' ')+'*';
        }
        
    }
    v[0]=string(mx+2, '*');
    v.push_back(v[0]);
    for (auto it: v) cout<<it<<endl;
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