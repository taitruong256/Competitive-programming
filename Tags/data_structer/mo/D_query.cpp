#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll block=175;
ll n, q, a[30005], ans[200005], cnt[1000005], res;

struct query
{
    ll l, r, idx;

    query(){}
    query(ll _l, ll _r, ll _idx)
    {
        l=_l;
        r=_r;
        idx=_idx;
    }

    bool operator < (query other)
    {
        return make_pair(l/block, ((l/block)&1)?r:-r)<make_pair(other.l/block, ((other.l/block)&1)?other.r:-other.r);
    }
};

void add(ll idx)
{
    if (cnt[a[idx]]==0) ++res;
    ++cnt[a[idx]];
}

void remove(ll idx)
{
    --cnt[a[idx]];
    if (cnt[a[idx]]==0) --res;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>q;
    vector<query> qry;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        qry.push_back(query(l, r, i));
    }
    sort(qry.begin(), qry.end());
    ll l=1, r=0;
    for (auto i: qry)
    {
        while (l<i.l) remove(l++);
        while (l>i.l) add(--l);
        while (r<i.r) add(++r);
        while (r>i.r) remove(r--);
        ans[i.idx]=res;
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
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
