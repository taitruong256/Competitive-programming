#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
map<ll, ll> cnt;
ll ans=0;

ll dem()
{
    ll x=0;
    for (ll i=0; i<5; i++)
        for (ll j=i; j<5; j++)
            for (ll k=j; k<5; k++)
                if ((i+k+j)%5==0)
                {
                    map<ll, ll> sl;
                    ++sl[i];
                    ++sl[j];
                    ++sl[k];
                    ll res=1;
                    for (auto i: sl)
                    {
                        ll n=cnt[i.first];
                        if (i.second==3) res=res*n*(n-1)*(n-2)/6;
                        else if (i.second==2) res=res*n*(n-1)/2;
                        else if (i.second==1) res=res*n;
                    }   //cout<<i<<" "<<j<<" "<<k<<" "<<res<<endl;
                    x+=res;
                }
    return x;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5];

    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        ++cnt[a[i]%5];
    }
    cout<<dem();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
//    #ifndef ONLINE_JUDGE
//    freopen("_input.txt", "r", stdin);
//    freopen("_output.txt", "w", stdout);
//    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}
