#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n; cin>>n;
    set<ll> s;
    for (int i=0; i<n; i++)
    {
        ll x; cin>>x;
        s.insert(x);
        auto it=lower_bound(s.begin(), s.end(), x); 
        if (it!=s.begin()) cout<<*(--it)<<"\n";
        else cout<<"-1\n";
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
