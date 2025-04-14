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
    string s, t; cin>>s>>t;   

    set<ll> pos[3];
    for (ll i=0; i<n; i++) pos[s[i]-'a'].insert(i);

    for (ll i=0; i<n; i++) 
    {
        if (s[i]!=t[i])
        {
            if (s[i]=='a' && t[i]=='b')
            {
                if (pos[1].empty())
                {
                    cout<<"NO\n";
                    return;
                }
                ll j=*pos[1].begin();
                if (pos[2].empty() || *pos[2].begin()>j)
                {
                    swap(s[i], s[j]);
                    pos[0].erase(i);
                    pos[0].insert(j);
                    pos[1].erase(j);
                    pos[1].insert(i);
                }
                else 
                {
                    cout<<"NO\n";
                    return;
                }
            }
            else if (s[i]=='b' && t[i]=='c')
            {
                if (pos[2].empty())
                {
                    cout<<"NO\n";
                    return;
                }
                ll j=*pos[2].begin();
                if (pos[0].empty() || *pos[0].begin()>j)
                {
                    swap(s[i], s[j]);
                    pos[1].erase(i);
                    pos[1].insert(j);
                    pos[2].erase(j);
                    pos[2].insert(i);
                }
                else 
                {
                    cout<<"NO\n";
                    return;
                }
            }
            else
            {
                cout<<"NO\n";
                return;
            }
        }
        pos[s[i]-'a'].erase(i);
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