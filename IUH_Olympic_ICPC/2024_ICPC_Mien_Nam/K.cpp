#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, p, m;
pair<ll, ll> vitri[10005];
ll huong[10005]; 
ll last_z=0;
ll dx=0, dy=0;

void solve()
{
    cin>>n>>p>>m;
    for (ll i=1; i<=p; i++)
    {
        cin>>vitri[i].first>>vitri[i].second>>huong[i];
        huong[i]-=1;
    }
    for (ll x=1; x<=m; x++)
    {
        char c;
        ll k;
        cin>>c>>k;
        if (c=='A')
        {
            if (huong[1]==0) dx=(dx-k+4*n)%n;
            else if (huong[1]==2) dx=(dx+k+4*n)%n;
            else if (huong[1]==1) dy=(dy+k+4*n)%n;
            else dy=(dy-k+4*n)%n;
        }
        else if (c=='R')
        {
            huong[1]=(huong[1]+k)%4;
        }
        else 
        {
            last_z=x;
            vitri[1].first=k/n;
            vitri[1].second=k%n;
        }
    }
    cout<<last_z<<endl;
    cout<<dx<<" "<<dy<<endl;
    if (last_z==0)
    {
        
    }
    else 
    {
        
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}