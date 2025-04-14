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
    ll n, k; cin>>n>>k;
    deque<ll> dq;
    set<ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        if (cnt.find(x)!=cnt.end()) continue;
        if (dq.size()<k) 
        {
           dq.push_front(x);
           cnt.insert(x);
        }
        else
        {
            dq.push_front(x);
            cnt.insert(x);
            cnt.erase(cnt.find(dq.back()));
            dq.pop_back();
        }
    }

    cout<<dq.size()<<endl;
    while (dq.size()>0)
    {
        cout<<dq.front()<<" ";
        dq.pop_front();
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