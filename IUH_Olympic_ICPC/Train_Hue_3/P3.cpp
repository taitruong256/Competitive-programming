/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct matran{ll a, b, c, d;};
ll mod=1e9+7;

matran tinh(matran x, matran y)
{
    matran kq;
    ll a, b, c, d, e, f, g, h;
    a=x.a; b=x.b; c=x.c; d=x.d;
    e=y.a; f=y.b; g=y.c; h=y.d;
    kq.a=(a*e%mod+b*g%mod)%mod;
    kq.b=(a*f%mod+b*h%mod)%mod;
    kq.c=(c*e%mod+d*g%mod)%mod;
    kq.d=(c*f%mod+d*h%mod)%mod;
    return kq;
}

matran luythua(matran x, matran y, ll n)
{
    if (n==1) return x;
    matran tam=luythua(x, y, n/2);
    if (n%2==1) return tinh(x, tinh(tam, tam));
    else return tinh(tam, tam);
}

void solve()
{
    ll n; cin>>n;
    matran t={1, 1, 1, 0};
    matran ans=luythua(t, t, n);
    //cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
    cout<<ans.a<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--)
    solve();
    return 0;
}