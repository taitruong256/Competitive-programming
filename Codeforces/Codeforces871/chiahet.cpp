#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void solve()
{
    string s; cin>>s; s=" "+s;
    ll id=1, n=s.size()-1;
    for (ll i=1; i<=n; i++) if (s[i]=='?') id=i;
    ll Tai=0;
    for (ll i=1; i<=n; i++) if (s[i]!='?') Tai+=s[i]-'0';
    Tai=9-Tai%9; 
    ll sum=0, mu=1;
    for (ll i=n; i>=1; i--)
    {
        if (s[i]!='?') sum=(sum+(s[i]-'0')*mu)%11;
        mu=(mu*10)%11;
    }
    ll p=binpow(10, n-id, 11);   
    ll Loc=-1;        
    for (ll i=0; i<=9; i++) if ((sum+i*p)%11==0) Loc=i;

    // cout<<Tai<<" "<<Loc<<endl;
    if (Tai>Loc) cout<<"Tai";
    else if (Tai<Loc) cout<<"Loc";
    else cout<<"Ban";
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