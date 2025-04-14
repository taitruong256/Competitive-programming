#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) b[i]=a[i];
    sort(b+1, b+n+1);
    for (ll i=1; i<=n-1; i++) if (a[i]!=b[i])
    {
        ll vitri=i, j;
        for (j=i; j<=n; j++) if (a[j]==b[i])
        {
            vitri=j;
            break;
        }
        for (ll j=vitri; j>=i+1; j--)
        {
            cout<<j-1<<" "<<j<<endl;
            swap(a[j-1], a[j]);
        }
        //cout<<i<<" "<<vitri<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
