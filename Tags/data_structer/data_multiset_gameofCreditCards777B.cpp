#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;
    string s1, s2; cin>>s1>>s2;
    multiset<char> ms;
    ll ans=0;
    for (ll i=0; i<n; i++) ms.insert(s2[i]);
    for (ll i=0; i<n; i++) 
    {
        auto it=ms.lower_bound(s1[i]);
        if (it!=ms.end()) ms.erase(it);
        else 
        {
            ++ans;
            ms.erase(ms.begin());
        }

    }
    cout<<ans<<"\n";
    ms.clear();
    ans=0;
    for (ll i=0; i<n; i++) ms.insert(s2[i]);
    for (ll i=0; i<n; i++) 
    {
        auto it=ms.upper_bound(s1[i]);
        if (it!=ms.end()) 
        {
            ++ans;
            ms.erase(it);
        }
        else ms.erase(ms.begin());

    }
    cout<<ans;
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
