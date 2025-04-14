#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod =  998244353;

struct matrix
{
    ll a[3][3];
};

matrix mul(matrix a, matrix b)
{
    matrix c;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++) c.a[i][j]=0;

    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++)
            for (ll k=1; k<=2; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mod;
            }
    return c;
}

matrix binpow(matrix a, ll n)
{
    matrix c;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++)
            if (i==j) c.a[i][j]=1;
            else c.a[i][j]=0;
    if (n==0) return c;
    c=binpow(a, n/2);
    c=mul(c, c);
    if (n%2==1) c=mul(c, a);
    return c;
}

void solve()
{
    ll n; cin>>n;
    matrix a;
    a.a[1][1]=1;
    a.a[1][2]=1;
    a.a[2][1]=1;
    a.a[2][2]=0;
    a=binpow(a, n+1);
    cout<<(a.a[1][1]*a.a[1][2])%mod;
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
