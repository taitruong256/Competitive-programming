#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

void solve()
{
    ll n; cin>>n;
    map<ll, ll> count;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        count[x]++;
    }
    priority_queue<ll> pq;
    for (auto it: count) pq.push(it.second);
    while (pq.size()>1)
    {
        ll a=pq.top(); pq.pop();
        ll b=pq.top(); pq.pop();
        a--; b--;
        if (a>0) pq.push(a);
        if (b>0) pq.push(b);
    }
    if (pq.size()>0) cout<<pq.top()<<endl;
    else cout<<0<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}