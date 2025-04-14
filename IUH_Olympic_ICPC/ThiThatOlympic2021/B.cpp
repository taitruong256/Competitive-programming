#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, q, a[1000005];

struct segment_
{
    ll n;
    vector<ll> min_value, sum_value;
    segment_(){}
    segment_(ll _n)
    {
        n=_n;
        min_value.resize(4*n+5);
        sum_value.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            min_value[id]=a[l-1];
            sum_value[id]=a[l-1];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        min_value[id]=min(min_value[id*2], min_value[id*2+1]);
        sum_value[id]=sum_value[id*2]+sum_value[id*2+1];
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e9;
        if (u<=l && r<=v) return min_value[id];
        ll mid=(l+r)/2;
        return min(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {

            min_value[id]=min(min_value[id*2], min_value[id*2+1]);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, u, v, val);
        min_value[id]=min(min_value[id*2], min_value[id*2+1]);
        sum_value[id]=sum_value[id*2]+sum_value[id*2+1];
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=0; i<n; i++) cin>>a[i];
    segment_ seg(n);
    ll st=0;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll d; cin>>d;
            d%=n;
            st=(st-d+n)%n;
        }
        else if (type==2)
        {
            ll l, r, val; cin>>l>>r>>val;
            ll newl=l+st-1;
            ll newr=r+st-1;        cout<<"2----"<<newl%n<<" "<<newr%n<<endl;
            newl%=n;
            newr%=n;
            seg.update(1, 1, n, newl+1, newr+1, val);
            cout<<seg.min_value[5]<<endl;
        }
        else
        {
            ll l, r; cin>>l>>r;
            ll newl=l+st-1;
            ll newr=r+st-1;          cout<<"3----"<<newl%n<<" "<<newr%n<<endl;
            if (newr<=n-1)
            {
                newl%=n;
                newr%=n;
                cout<<seg.query(1, 1, n, newl+1, newr+1)<<endl;
            }
            else
            {
                newl%=n;
                newr%=n;
                ll truoc=seg.query(1, 1, n, newl+1, n);
                ll sau=seg.query(1, 1, n, 1, newr+1);
                ll mn=min(truoc, sau);
                cout<<mn<<endl;
            }
        }
    }
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
