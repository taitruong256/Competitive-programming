#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n, m; cin>>n>>m;
    ll l=1, r=n;
    for (ll i=0; i<m; i++)
    {
        string a, b, c, d;
        ll t;
        cin>>a>>b>>c>>d>>t;
        if (c=="left") r=min(r, t-1);
        else l=max(l, t+1);
    }
    if (l>r)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<r-l+1<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}