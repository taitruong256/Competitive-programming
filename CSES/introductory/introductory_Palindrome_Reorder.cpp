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
    string s; cin>>s;
    map<char, ll> cnt;
    for (auto c: s) ++cnt[c];
    ll d=0;
    for (char c='A'; c<='Z'; c++) if (cnt[c]%2==1) ++d;
    if (d>1) cout<<"NO SOLUTION";
    else
    {
        deque<char> dq;
        for (char c='A'; c<='Z'; c++) if (cnt[c]%2==1) dq.push_back(c), --cnt[c];
        for (char c='Z'; c>='A'; c--) if (cnt[c]>=2)
            for (ll i=0; i<cnt[c]/2; i++) dq.push_front(c), dq.push_back(c);
        while (!dq.empty()) 
        {
            cout<<dq.front(); dq.pop_front();
        }
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