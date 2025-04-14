#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    ll last[256];
    set<char> active;
    for (ll i=0; i<n; i++) last[s[i]]=i;
    for (ll i=0; i<n; i++)
    {
        active.insert(s[i]);
        if (active.size()>k) 
        {
            cout<<"YES"; return;
        }
        if (last[s[i]]==i) active.erase(s[i]);
    }
    cout<<"NO";
}

int main() {                   
    FAST;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
