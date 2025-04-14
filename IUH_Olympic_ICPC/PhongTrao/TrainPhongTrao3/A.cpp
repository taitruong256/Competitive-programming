#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    string s; cin>>s;
    s="0"+s+"0";
    for (ll i=1; i<=m; i++)
    {
        string t=s;
        for (ll j=1; j<=n; j++) if (s[j]=='0')
        {
            ll cnt=(s[j-1]=='1')+(s[j+1]=='1');  //cout<<cnt<<" ";
            if (cnt==1) t[j]='1';

        }
        if (t==s) break;
        s=t;                   //cout<<t<<endl;
    }
    s.erase(0, 1);
    s.erase(s.size()-1, 1);
    cout<<s<<endl;
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
