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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int 
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, q;
vector<ll> a(200005);


struct wavelet_tree  //luu y bo nho n*log(n)
{
    ll lo, hi;
    vector<ll> val, fre, v1, v2;
    wavelet_tree *l, *r;
    wavelet_tree(){}
    wavelet_tree(ll n, ll low, ll high, vector<ll> a)   //vector a co n+1 phan tu, phan tu dau tien = 0
    {
        lo=low; hi=high;
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
        l=new wavelet_tree(n, low, mid, v1);
        r=new wavelet_tree(n, mid+1, high, v2);
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
};


void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    wavelet_tree seg(n, 1, 200000, a);

    while (q--)
    {
        ll ql, qr; cin>>ql>>qr;
        ll l=1, r=qr-ql+1, len=qr-ql+1, ans=-1; 
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (seg.kth(ql, qr, len-mid+1)>=mid) ans=mid, l=mid+1;
            else r=mid-1;
        }
        assert(ans!=-1);
        cout<<ans<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}