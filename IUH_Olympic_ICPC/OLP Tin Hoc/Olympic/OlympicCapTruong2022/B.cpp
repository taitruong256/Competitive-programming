/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n, k; 
ll a[1000005];

void debugg(deque<ll> dq)
{
    while (!dq.empty())
    {
        cout<<a[dq.front()]<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll ans=-1e18;
    deque<ll> dq;
    for (ll i=1; i<=k; i++)
    {
        if (dq.front()<i-k+1) dq.pop_front();
        if (dq.empty()) dq.push_back(i);
        else
        {
            //cout<<"----"<<dq.back()<<endl;
            while (dq.size()>0 && a[dq.back()]>a[i]) dq.pop_back();
            dq.push_back(i);
        }
    }
    ans=max(ans, a[dq.front()]);

    for (ll i=k+1; i<=n; i++)
    {
        if (dq.front()<i-k+1) dq.pop_front();
        if (dq.empty()) dq.push_back(i);
        else
        {
            //cout<<"----"<<dq.back()<<endl;
            while (dq.size()>0 && a[dq.back()]>a[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans=max(ans, a[dq.front()]);   // debugg(dq);
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
    solve();
    return 0;
}