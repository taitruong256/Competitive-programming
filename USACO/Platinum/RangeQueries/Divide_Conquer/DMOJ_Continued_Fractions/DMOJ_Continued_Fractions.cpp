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
ll n, q, x;

struct matrix
{
    ll num[2][2];
    matrix()
    {
        for (ll i=0; i<2; i++)
            for (ll j=0; j<2; j++)
                num[i][j]=0;
    }
};

matrix calc(ll x)
{
    matrix a;
    a.num[0][0]=x;
    a.num[0][1]=a.num[1][0]=1;
    a.num[1][1]=0;
    return a;
}

matrix operator* (matrix a, matrix b)
{
    matrix c;
    for (ll i=0; i<2; i++)
        for (ll j=0; j<2; j++)
            for (ll k=0; k<2; k++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j], c.num[i][j]%=mod;
    return c;
}

matrix a[300005], ans[300005], le[300005], ri[300005];
pair<ll, ll> qry[300005];

void divide_and_conquer(ll l, ll r, vector<ll> idx)
{
    if (l==r)
    {
        for (ll i: idx) ans[i]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    le[mid]=a[mid];
    for (ll i=mid-1; i>=l; i--) le[i]=a[i]*le[i+1];
    ri[mid+1]=a[mid+1];
    for (ll i=mid+2; i<=r; i++) ri[i]=ri[i-1]*a[i];
    vector<ll> todo[2];
    for (ll i: idx)
    {
        auto [lt, rg]=qry[i];
        if (lt<=mid && mid<rg) ans[i]=le[lt]*ri[rg];
        else todo[lt>mid].push_back(i);
    }
    divide_and_conquer(l, mid, todo[0]);
    divide_and_conquer(mid+1, r, todo[1]);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>x, a[i]=calc(x);
    for (ll i=1; i<=q; i++) cin>>qry[i].first>>qry[i].second;
    vector<ll> idx;
    for (ll i=1; i<=q; i++) idx.push_back(i);
    divide_and_conquer(1, n, idx);
    for (ll i=1; i<=q; i++) cout<<ans[i].num[0][0]<<" "<<ans[i].num[1][0]<<endl;
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