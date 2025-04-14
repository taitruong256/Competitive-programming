/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll left=0, right=0, cnt=0, ans=0;
    deque<ll> dq;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        dq.push_back(x);
    }
    while (!dq.empty())
    {
        if (left==right) ans=cnt, left+=dq.front(), dq.pop_front(), ++cnt; 
        else if (left<right) left+=dq.front(), dq.pop_front(), ++cnt;
        else right+=dq.back(), dq.pop_back(), ++cnt; 
        if (left==right) ans=cnt;
        // cout<<left<<" "<<right<<endl;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}