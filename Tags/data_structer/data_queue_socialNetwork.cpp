#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k; 
    map<ll, ll> count;
    queue<ll> q;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        if (count[x]==1) continue;
        q.push(x);
        count[x]=1;
        if (q.size()==k+1)
        {
            count[q.front()]=0;
            q.pop();
        }
        
    }
    vector<ll> ans;
    cout<<q.size()<<"\n";
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    for (ll i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";

}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
