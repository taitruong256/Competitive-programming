#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[1005][1005];

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    ll q, redline; cin>>q>>redline;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll c, c1, r1, c2, r2; cin>>c>>c1>>r1>>c2>>r2;
            bool check=false;
            for (ll i=r1; i<=r2; i++)
                for (ll j=c1; j<=c2; j++) if (check==false && a[i][j]<redline)
                {
                    cout<<0<<endl;
                    check=true;
                }
            if (check==true) continue;
            ll s=0, x=r1, y=c1, huong=1;
            ll cnt=(c2-c1+1)*(r2-r1+1);
            while (cnt--)
            {
                if (a[x][y]>=redline) s+=a[x][y]-redline, a[x][y]=redline;
                if (s>c)
                {
                    ll thua=s-c;
                    a[x][y]+=thua;
                    s-=thua;
                    break;
                }
                if (x>r2) break;
                y+=huong;
                if (y>c2) huong=-huong, ++x, y=c2;
                if (y<c1) huong=-huong, ++x, y=c1;
            }
            cout<<s<<endl;
        }
        else
        {
            ll redl; cin>>redl;
            redline=redl;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
