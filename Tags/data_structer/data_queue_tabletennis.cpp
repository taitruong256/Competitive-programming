#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
using namespace std;

void solve()
{
    ll n, k, maxx=0; cin>>n>>k;
    queue<ll> q;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        if (x>maxx) maxx=x;
        q.push(x);
    }
    if (k>=n) 
    {
        cout<<maxx;
        return ;
    }

    ll a=q.front(); q.pop();
    ll b=q.front(); q.pop();
    ll d=1, best=a>b?a:b;
    while (true)
    {
        ll t=q.front();
        q.pop();
        if (t>best)
        {
            d=1;
            q.push(best);
            best=t;
        }
        else 
        {
            ++d;
            q.push(t);
        }          // cout<<best<<" "<<t<<endl;
        if (d>=k) break;
    }
    cout<<best;
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
