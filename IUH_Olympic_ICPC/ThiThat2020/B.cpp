#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll k; cin>>k;
    string s; cin>>s;
    s=" "+s;
    ll l=1, n=s.size()-1, a=0, v=0, c=0, ans=1e9;
    for (ll r=1; r<=n; r++)
    {
        if (s[r]=='A') ++a;
        if (s[r]=='V') ++v;
        if (s[r]=='C') ++c;
        while (a>=k && v>=k && c>=k)
        {
            ans=min(ans, r-l+1-3*k);
            if (s[l]=='A') --a;
            if (s[l]=='V') --v;
            if (s[l]=='C') --c;
            ++l;
        }
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
