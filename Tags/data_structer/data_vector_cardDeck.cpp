#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, q; cin>>n>>q;
    vector<ll> a(n);
    for (auto& x:a) cin>>x;
    for (ll i=0; i<q; i++)
    {
        ll t; cin>>t;
        ll pos=find(a.begin(), a.end(), t)-a.begin();
        cout<<pos+1<<" ";
        rotate(a.begin(), a.begin()+pos, a.begin()+pos+1);
    }
}

int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
