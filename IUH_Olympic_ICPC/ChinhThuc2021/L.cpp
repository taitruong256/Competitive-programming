#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+1];
    vector<ll> chan, le;
    ll schan=0, sle=0;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        if (a[i]%2==0) 
        {
            chan.push_back(a[i]);
            schan+=a[i];
        }
        else 
        {
            le.push_back(a[i]);
            sle+=a[i];
        }
    }
    string s; cin>>s;
    for (ll i=0; i<s.size(); i++) 
    if (s[i]=='0')
    {
        schan=0;
        for (ll j=0; j<chan.size(); j++)
        {
            schan+=chan[j];
            chan[j]/=2;
            if (chan[j]%2==1) 
            {
                le.push_back(chan[j]);
                chan.erase(chan.begin()+j);
            }
        }
    }
    else
    {
        sle=0;
        for (ll j=0; j<le.size(); j++)
        {
            sle=le.size();
            for (j=1; )
            le.erase(le.begin(), le.end());
        }
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
