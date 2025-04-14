#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
||             Nothing is impossible, only you think it is impossible                 ||
||                     Try, try, try again until you succeed                          ||
 =====================================================================================
*/
void solve()
{  
    ll n; cin>>n;
    ll a[n];
    vector<pair<ll, ll>> v, ans;
    ll known[n];
    memset(known, false, sizeof(known));
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        if (i>0) v.push_back({a[i], i});
    }

    queue<ll> q;
    q.push(0);
    known[0]=true;
    sort(v.rbegin(), v.rend());
    while (!q.empty())
    {
        ll id=q.front();
        q.pop();
        while (a[id]>0)
        {
            --a[id];
            for (auto it:v) if (!known[it.second]) 
            {
                known[it.second]=true;
                q.push(it.second);
                ans.push_back({id+1, it.second+1});
                break;
            }
        }
    }
 
    for (ll i=0; i<n; i++) if (!known[i])
    {
        cout<<-1;
        return;
    }
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}