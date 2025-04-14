#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

struct hinhvuong
{
    ll x1, y1, x2, y2;  //duoi trai, tren phai
};

struct diem
{
    ll x, y;  
};

bool namtrong(diem d, hinhvuong hv)
{
    if (hv.x1<=d.x && d.x<=hv.x2 && hv.y1<=d.y && d.y<=hv.y2) return true;
    return false;
}

pair<hinhvuong, hinhvuong> truonghop(ll n, ll minx, ll maxx, ll miny, ll maxy, ll len)
{
    if (n==1) return {{minx, maxy-len, minx+len, maxy}, {minx, miny, minx+len, miny+len}};
    if (n==2) return {{minx, maxy-len, minx+len, maxy}, {maxx-len, maxy-len, maxx, maxy}};
    if (n==3) return {{minx, maxy-len, minx+len, maxy}, {maxx-len, miny, maxy, miny+len}};
    if (n==4) return {{minx, miny, minx+len, miny+len}, {maxx-len, miny, maxx, miny+len}};
    if (n==5) return {{minx, miny, minx+len, miny+len}, {maxx-len, maxy-len, maxx, maxy}};
    return {{maxx-len, maxy-len, maxx, maxy}, {maxx-len, miny, maxx, miny+len}};
}

ll n;
diem p[100005];

bool check(hinhvuong hv1, hinhvuong hv2)
{
    for (ll i=1; i<=n; i++) if (namtrong(p[i], hv1)==false && namtrong(p[i], hv2)==false) return false;
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>p[i].x>>p[i].y;
    ll minx=1e18, maxx=-1e18, miny=1e18, maxy=-1e18; 
    for (ll i=1; i<=n; i++)
    {
        minx=min(minx, p[i].x);
        maxx=max(maxx, p[i].x);
        miny=min(miny, p[i].y);
        maxy=max(maxy, p[i].y);
    }
    ll ans=1e18;
    for (ll i=1; i<=6; i++)
    {
        ll l=0, r=2e9+5;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            auto [hv1, hv2]=truonghop(i, minx, maxx, miny, maxy, mid);
            if (check(hv1, hv2)==true) ans=min(ans, mid), r=mid-1;
            else l=mid+1;
        }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}