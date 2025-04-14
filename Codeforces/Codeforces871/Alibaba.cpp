#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;
const ll maxx = 1e6;
ll isprime[maxx+5];

void solve()
{
    for (ll i=2; i*i<=maxx; i++) isprime[i]=true;
    for (ll i=2; i*i<=maxx; i++) if (isprime[i]==true)
        for (ll j=i*i; j<=maxx; j+=i) isprime[j]=false;
    ll n=10;
    ll x[2*n+5];
    for (ll i=1; i<=2*n; i++) cin>>x[i];
    sort(x+1, x+2*n+1);
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) a[i]=x[i];
    for (ll i=1; i<=n; i++) b[i]=x[i+10];
    bool Ban=false, Manh=false;
    do 
    {
        ll check=true;
        for (ll i=1; i<=n-1; i++) if (isprime[abs(a[i+1]-a[i])]==false)
            check=false;
        if (check==true) 
        {
            Ban=true; 
            // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
            break;
        }
    }
    while (next_permutation(a+1, a+n+1));
    do 
    {
        ll check=true;
        for (ll i=1; i<=n-1; i++) if (isprime[abs(b[i+1]-b[i])]==false)
            check=false;
        if (check==true) 
        {
            Manh=true; 
            // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
            break;
        }
    }
    while (next_permutation(b+1, b+n+1));
    if (Ban==true && Manh==true) cout<<"OH YEAH";
    else if (Ban==false && Manh==false) cout<<"OH NO";
    else cout<<"OKELA";
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