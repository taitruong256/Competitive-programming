#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    ll n; cin>>n;
    map<ll, ll> count;
    for (int i=0; i<n; i++)
    {
        ll x; cin>>x;
        count[x]++;
    }

    ll MEX=0;
    for (ll i=0; i<=n; i++) if (count[i]==0)
    {
        MEX=i;
        break;
    }

    stack<ll> st;
    for (ll i=0; i<=MEX; i++) 
    {
        cout<<count[i]<<" ";
        if (count[i]>1) 
            for (ll j=0; j<count[i]-1; j++) st.push(i);
    }


    ll s=0;
    for (ll i=MEX+1; i<=n; i++)
    {
        if (!st.empty())
        {
            s+=(i-1-st.top());
            st.pop();
            if (count[i]==0) cout<<s<<" ";
            else 
            {
                cout<<s+count[i]<<" ";
                for (int j=0; j<count[i]; j++) st.push(i);
            }
        }
        else cout<<-1<<" ";
    }
    cout<<endl;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
