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
    deque<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        q.push_back(x);
        pq.push(x);
    }

    ll ans=0;
    while (!q.empty())
    {
        if (q.front()==pq.top()) 
        {
            q.pop_front();
            pq.pop();
        }
        else
        {
            ll it=q.front();
            q.pop_front();
            q.push_back(it);
        }
        ++ans;
    }
    cout<<ans;
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