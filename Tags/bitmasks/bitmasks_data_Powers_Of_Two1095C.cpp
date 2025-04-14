/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;     
    priority_queue<ll> que;
    for (ll i=0; i<32; i++) if (n&(1<<i)) que.push(1<<i);

    if (que.size()>k || k>n) 
    {
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    while (que.size()<k)
    {
        ll x=que.top();
        que.pop();
        que.push(x/2);
        que.push(x/2);
    }
    while (!que.empty())
    {
        cout<<que.top()<<" ";
        que.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}