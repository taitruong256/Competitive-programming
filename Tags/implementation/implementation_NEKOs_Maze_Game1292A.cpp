#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

void solve()
{
    ll n, q; cin>>n>>q;
    bool mark[3][200005];
    memset(mark, true, sizeof(mark));
    ll count=0;
    for (ll i=0; i<q; i++)
    {
        ll r, c; cin>>r>>c;
        if (mark[r][c]==true)
        {
            mark[r][c]=false;
            for (ll j=-1; j<=1; j++) if (mark[3-r][c+j]==false) ++count;
        }
        else
        {
            mark[r][c]=true;
            for (ll j=-1; j<=1; j++) if (mark[3-r][c+j]==false) --count;
        }
        //cout<<count<<endl;
        if (count==0) cout<<"Yes\n"; else cout<<"No\n";
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                // cin>>t;
    while (t--) solve();
    return 0;
}