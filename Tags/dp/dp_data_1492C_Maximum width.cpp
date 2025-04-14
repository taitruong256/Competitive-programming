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
    ll n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    deque<ll> dq;
    for (ll i=0; i<n; i++) dq.push_back(i);
    ll right[n+5], left[n+5];
    for (ll i=m-1; i>=0; i--)
    {
        while (!dq.empty() && s[dq.back()]!=t[i]) dq.pop_back();
        right[i]=dq.back();
    }
    for (ll i=0; i<m; i++) cout<<right[i]<<" ";
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