/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
ll n, q, a[100005];
vector<ll> v;

struct wavelet_tree
{
    ll lo, hi;
    vector<ll> val, fre, v1, v2;
    wavelet_tree *l, *r;
    wavelet_tree(){}
    wavelet_tree(ll n, ll x, ll y, vector<ll> a)
    {
        lo=x; hi=y;
        if (lo==hi) return;
        val.push_back(0); v1.push_back(0); v2.push_back(0);
        for (ll i=1; i<(ll)(a.size()); i++) if (a[i]>=lo && a[i]<=hi) val.push_back(a[i]);
        ll mid=(lo+hi)/2;
        fre.push_back(0);
        for (ll i=1; i<(ll)(val.size()); i++) 
        {
            if (val[i]<=mid) v1.push_back(val[i]);
            else v2.push_back(val[i]);
            fre.push_back(fre.back()+(val[i]<=mid));
        }
        l=new wavelet_tree(n, x, mid, v1);
        r=new wavelet_tree(n, mid+1, y, v2);
    }
    ll kth(ll l, ll r, ll k) //so lon thu k trong doan l->r
    {
        if (lo==hi) return lo;
        ll chuyen=fre[r]-fre[l-1], newl=fre[l-1], newr=fre[r];
        if (k<=chuyen) return this->l->kth(newl+1, newr, k);
        return this->r->kth(l-newl, r-newr, k-chuyen);
    }
    ll LTE(ll l, ll r, ll k) //dem so luong <=k trong doan l->r
    {
        if (k<lo) return 0;
        if (hi<=k) return r-l+1;
        ll chuyen=fre[r]-fre[l-1], newl=fre[l-1], newr=fre[r];
        return this->l->LTE(newl+1, newr, k)+this->r->LTE(l-newl, r-newr, k);
    }
    ll count(ll l, ll r, ll k) //dem so luong =k trong doan l->r
    {
        if (k<lo || k>hi) return 0;
        if (lo==hi) return r-l+1;
        ll newl=fre[l-1], newr=fre[r], mid=(lo+hi)/2;
        if (k<=mid) return this->l->count(newl+1, newr, k);
        return this->r->count(l-newl, r-newr, k);
    }
    ~wavelet_tree()
    {
        delete l;
        delete r;
    }
};

void solve()
{
    cin>>n;
    v.push_back(0);
    set<ll> st;
    map<ll, ll> nen, giainen;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    } 
    ll id=0;
    for (auto i: st)
    {
        ++id;
        nen[i]=id;
        giainen[id]=i;
    }
    for (ll i=1; i<=n; i++) v.push_back(nen[a[i]]);

    wavelet_tree *T=new wavelet_tree(n, 1, id, v);
    cin>>q;
    while (q--)
    {
        ll l, r, k; cin>>l>>r>>k;
        cout<<giainen[T->kth(l, r, k)]<<endl;
    }
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