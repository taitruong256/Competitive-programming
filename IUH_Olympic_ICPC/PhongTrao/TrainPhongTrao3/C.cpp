#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b; cin>>a>>b;
    ll ans=0;
    if (a==0 || b==0)
    {
        cout<<0<<endl;
        return;
    }
    if (a==b)
    {
        cout<<1<<endl;
        return;
    }
    while (a>0 && b>0)
    {
        if (a<b) swap(a, b);     // cout<<a<<" "<<b<<endl;

        ll cnt=a/b; // cout<<cnt<<endl;
        a=a-cnt*b;
        ans+=cnt;
    }
    if (a>0 && b>0) ++ans;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
