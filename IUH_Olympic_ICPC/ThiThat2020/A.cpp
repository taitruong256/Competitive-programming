#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tinh(ll x)
{
    ll p=2, ans=0;
    while (p<=x)
    {
        ans+=x/p;
        p*=2;
    }
    return ans;
}

void solve()
{
    ll l, r; cin>>l>>r;
    cout<<tinh(r)-tinh(l-1);
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
