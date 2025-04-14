/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    bool dau[n+5];
    ll ans=1;
    memset(dau, false, sizeof(dau));
    set<ll> s;
    ll last=n;
    for (ll i=n; i>=1; i--) if (dau[i]==false)
    {             cout<<"   "<<i<<endl;
        for (ll j=last; j>=1; j--)
        {
            s.insert(a[j]);
            last=j;
            dau[a[j]]=true;
            if (a[j]==i) 
            {
                if (s.lower_bound(a[j])==s.begin()) ++ans;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}