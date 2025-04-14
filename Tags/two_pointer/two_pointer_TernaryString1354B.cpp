#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF 1e9+5

void solve()
{
    string s; cin>>s;
    ll d[4];
    d[1]=d[2]=d[3]=0;
    ll ans=INF, j=0, n=s.size();
    for (ll i=0; i<n; i++) 
    {    
        ++d[s[i]-'0'];
        if (d[1]!=0 && d[2]!=0 && d[3]!=0)
        {
            while (d[1]!=0 && d[2]!=0 && d[3]!=0)
            {
                --d[s[j]-'0'];
                ++j;
            }
            ans=min(ans, i-j+2);
        }     

        //cout<<"------"<<i<<" "<<j<<" ----- "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
    }

    if (ans==INF) ans=0;
    cout<<ans<<endl;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
