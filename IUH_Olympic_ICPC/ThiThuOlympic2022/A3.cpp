#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct fenwick
{
    ll n;
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n){n=_n, bit.resize(n+5);}

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll s=0;
        for (ll i=idx; i>0; i-=-i&i) s+=bit[i];
        return s;
    }
};

void solve()
{
    ll n; cin>>n;
    ll a[n+5], khacbiet[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    fenwick ft(n+5);
    map<ll, ll> pre;
    ll ans=0;
    khacbiet[0]=0;
    for (ll r=1; r<=n; r++)
    {
        ft.update(r, 1);
        if (pre[a[r]])
        {
            ll l=pre[a[r]];
            ft.update(l, -1);
            ll phanbiet=r-l-1-ft.query(r-1)+ft.query(l-1);
            ans+=phanbiet;
            // cout<<"----"<<l<<" "<<r<<" "<<phanbiet<<endl;
            // cout<<phanbiet<<endl;
        }
        else
        {
            ll cnt=ft.query(r)-1;
            ans+=cnt;
            // cout<<"----"<<1<<" "<<r<<endl;
            // cout<<cnt<<endl;
        }
        pre[a[r]]=r;
    }
    cout<<ans;
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
