#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;


bool check(ll n, vector<ll> &v)
{
    for (ll i: v)
    {
        while (n%i==0) n/=i;
    }
    return n==1;
}


void solve()
{
    ll n; cin>>n;
    

    ll nt=2, m=n;
    vector<ll> uoc;
    while (m>1)
    {
        if (m%nt==0)
        {
            uoc.push_back(nt);
            while (m%nt==0) m/=nt;
        }
        ++nt;
    }


    ll ans=0;
    for (ll i=1; i*i<=n; i++) if (check(i*i, uoc)==1) ++ans;
    for (ll i=1; i*i*i<=n; i++) if (check(i*i*i, uoc)==1) ++ans;
    for (ll i=1; i*i*i*i*i*i<=n; i++) if (check(i*i*i*i*i*i, uoc)==1) --ans;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}