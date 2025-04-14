#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, s=0; cin>>n; 
    map<ll, ll> count;
    count.clear();
    for (ll i=0; i<n; i++)
    {
        ll l, r; cin>>l>>r;
        ++count[l];
        --count[r];
    }
    ll k=0, y=1, max=0;
    for(auto i:count) 
    {     
        k+=i.second;
        if (k>max)
        {
            max=k;
            y=i.first;
        }
    }
    cout<<y<<" "<<max;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
