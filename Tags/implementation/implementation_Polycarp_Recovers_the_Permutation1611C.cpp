/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void in(deque<ll> q)
{
    while (q.size()>0)
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

void solve()
{
    deque<ll> dq, a;
    ll n; cin>>n;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    while (a.size()>0)
    {  //    in(dq);
        if (a.front()<a.back())
        {
            dq.push_front(a.front());       
            a.pop_front();
        }
        else
        {
            dq.push_back(a.back());
            a.pop_back();
        }
    }
    while (dq.size()>0)
    {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}