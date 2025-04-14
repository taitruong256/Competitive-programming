#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll sum=0;
    for (ll i=1; i<=n-1; i++)
    {
        if (k>=a[i])
        {
            k-=a[i];
            a[n]+=a[i];
            a[i]=0;
        }
        else
        {
            a[i]-=k;
            a[n]+=k;
            break;
        }
    }
    for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
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
