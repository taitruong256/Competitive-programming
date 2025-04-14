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
    string s; cin>>s;
    deque<char> dq;
    for (ll i=0; i<n; i++)
    {
        if (i%2==0) dq.push_back(s[i]);
        else dq.push_front(s[i]);
    }
    if (n%2==1)
    {
        while (!dq.empty())
        {
            cout<<dq.front();
            dq.pop_front();
        }
    }
    else
    {
        while (!dq.empty())
        {
            cout<<dq.back();
            dq.pop_back();
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