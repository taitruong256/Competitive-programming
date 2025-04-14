#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

float khoangcach(ll x1, ll y1, ll x2, ll y2)
{
    return (sqrt(  (x1-x2)*(x1-x2)  +  (y1-y2)*(y1-y2))  );
}

float DTtamgiac(float a, float b, float c)
{
    float p=(a+b+c)/2;
    return sqrt(  p*(p-a)*(p-b)*(p-c)  );
}

bool kiemtra(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    float a=khoangcach(x1, y1, x2, y2);
    float b=khoangcach(x2, y2, x3, y3);
    float c=khoangcach(x3, y3, x1, y1);
    float slon=DTtamgiac(a, b, c);     
    return true;
}

void solve()
{
    ll x[9], y[9];
    for (ll i=1; i<=4; i++)
    {
        cin>>x[i]>>y[i];
        x[i+4]=x[i];
        y[i+4]=y[i];
    }
    for (int i=1; i<=4; i++)
    {
        bool co=kiemtra(x[i], y[i], x[i+1], y[i+1], x[i+2], y[i+2], x[i+3], y[i+3]);
        if (co==true) cout<<"YES";
        else cout<<"NO";
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
