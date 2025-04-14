#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll block=175;
ll n, q, a[30005], ans[200005], cnt[1000005], res;

struct query
{
    ll l, r, idx, ord;

    query(){}
    query(ll _l, ll _r, ll _idx)
    {
        l=_l;
        r=_r;
        idx=_idx;
        ord=HilbertOrder(l, r, 21, 0);
    }

    inline ll HilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = 1LL << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = HilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

    bool operator < (query other)
    {
        return ord<other.ord;
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
