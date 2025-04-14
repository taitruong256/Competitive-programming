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

bool check(string s)
{
    for (ll i=0; i<s.size(); i++) if (s[i]!='1') return false;
    return true;
}

void solve()
{
    ll n, x; cin>>n>>x;
    while (true)
    {
        if (check(to_string(x))==true) 
        {
            cout<<-1;
            return;
        }
        string s=
        if (to_string(x).size()>=n) break;
        for (ll i=)
    }
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
