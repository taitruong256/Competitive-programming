/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    ll mx=-1, pos=0;
    for (ll i=1; i<=n; i++) if (cnt[a[i]]>mx)
    {
        mx=cnt[a[i]];
        pos=i;
    }

    cout<<n-mx<<endl;
    for (ll i=pos-1; i>=1; i--) if (a[i]!=a[pos])
    {
        if (a[i]<a[pos]) 
        {
            cout<<1<<" "<<i<<" "<<i+1<<endl;
            a[i]=a[pos];
        }
        else 
        {
            cout<<2<<" "<<i<<" "<<i+1<<endl;
            a[i]=a[pos];
        }
    }

    for (ll i=pos+1; i<=n; i++) if (a[i]!=a[pos])
    {
        if (a[i]<a[pos]) 
        {
            cout<<1<<" "<<i<<" "<<i-1<<endl;
            a[i]=a[pos];
        }
        else 
        {
            cout<<2<<" "<<i<<" "<<i-1<<endl;
            a[i]=a[pos];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_<<endl;
        solve();
    }
    return 0;
}