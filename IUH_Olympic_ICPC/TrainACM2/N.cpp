/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    priority_queue<ll> pq;
    ll val=n;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        pq.push(x);
        while (pq.size()>0 && pq.top()==val)
        {
            cout<<val<<" ";
            pq.pop();
            --val;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}