#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, m; cin>>n>>m;
    set<string> st;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        st.insert(s);
    }
    for (ll i=0; i<m; i++)
    {
        string s; cin>>s;
        st.insert(s);
    }
    if (st.size()%2==1) ++n;
    if (n>m) cout<<"YES"; else cout<<"NO";
}

int main() {                   
    FAST;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
