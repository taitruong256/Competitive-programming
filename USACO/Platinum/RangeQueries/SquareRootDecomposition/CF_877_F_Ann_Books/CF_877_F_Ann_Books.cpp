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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
 
struct Mo
{
    ll l, r, id, block_size;
    Mo(){}
    Mo(ll _l, ll _r, ll _id, ll _n)
    {
        l=_l;
        r=_r;
        id=_id;
        block_size=ceil(sqrt(_n));
    }
    bool operator< (Mo other)
    {
        if (l/block_size!=other.l/block_size) return l/block_size<other.l/block_size;
        if (l/block_size%2==1) return r<other.r;
        return r>other.r;
    }
};
 
ll n, k, q, t[100005], a[100005], pref[100005], cnt[400005], ans[100005], idx[100005][3];
vector<Mo> qry;
vector<ll> compress;
 
void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>t[i], t[i]=(t[i]==2)?-1:1;
    for (ll i=1; i<=n; i++) cin>>a[i], a[i]*=t[i];
 
    compress.push_back(-k);
    compress.push_back(0);
    compress.push_back(k);
    for (ll i=1; i<=n; i++) 
    {
        pref[i]=pref[i-1]+a[i];
        compress.push_back(pref[i]);
        compress.push_back(pref[i]-k);
        compress.push_back(pref[i]+k);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end())-compress.begin());
    for (ll i=0; i<=n; i++) 
    {
        idx[i][0]=lower_bound(compress.begin(), compress.end(), pref[i]-k)-compress.begin()+1;
        idx[i][1]=lower_bound(compress.begin(), compress.end(), pref[i])-compress.begin()+1;
        idx[i][2]=lower_bound(compress.begin(), compress.end(), pref[i]+k)-compress.begin()+1;
    }
 
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        qry.push_back({l, r, i, n});
    }
    sort(qry.begin(), qry.end());
    ll l=1, r=0, total=0;
    ++cnt[idx[0][1]];
    for (auto [lx, rx, id, zz]: qry)
    {
        while (l<lx)
        {
            --cnt[idx[l-1][1]];
            total-=cnt[idx[l-1][2]];
            ++l;              
        }
        while (l>lx)
        {
            --l;
            total+=cnt[idx[l-1][2]];
            ++cnt[idx[l-1][1]];    
            
        }
        while (r<rx)
        {
            ++r;
            total+=cnt[idx[r][0]];
            ++cnt[idx[r][1]];  
        }
        while (r>rx)
        {
            --cnt[idx[r][1]];
            total-=cnt[idx[r][0]];  
            --r;            
        }
        ans[id]=total;    
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
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
