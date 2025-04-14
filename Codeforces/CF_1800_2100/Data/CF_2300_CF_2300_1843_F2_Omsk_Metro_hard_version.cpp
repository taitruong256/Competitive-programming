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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Ban đầu có một cây có 1 đỉnh, gốc là 1 và trọng số của đỉnh là 1.
Có n thao tác, mỗi thao tác thuộc 1 trong 2 loại sau:
    -Thêm một đỉnh con vào đỉnh u, và có trọng số là x thuộc {-1, 1}.
    -Hỏi có đoạn con trên đường đi từ u đến v sao cho tổng trọng số là k.

Input
1
8
+ 1 -1
? 1 1 2
? 1 2 1
+ 1 1
? 1 3 -1
? 1 1 1
? 1 3 2
? 1 1 0
Output
NO
YES
NO
YES
YES
YES

Ý tưởng:
Gọi mx là giá trị lớn nhất của tổng đoạn con trên đường đi từ u đến v.
Gọi mn là giá trị nhỏ nhất của tổng đoạn con trên đường đi từ u đến v.
Đoạn con có tổng =k sẽ tồn tại nếu mn<=k<=mx.

Chứng minh: trên đường đi từ u đến v, muốn lấy được phân đoạn có tổng =k thì ta sẽ liên tục thêm/xóa đỉnh ở đầu/cuối đường đi.
Vì trọng số thuộc {-1, 1} nên tổng trọng số phân đoạn đường đi sẽ tăng hoặc giảm đi 1. Nói cách khác, bất kể ta đi từ đoạn này 
sang đoạn khác như thế nào thì tổng vẫn sẽ là giá trị liên tục rời rạc nằm trong đoạn [mn, mx] (theo định lý giá trị trung gian).

Để tìm tổng đoạn con lớn nhất và nhỏ nhất, ta dùng nâng nhị phân để lưu giá trị tiền tố lớn nhất/nhỏ nhất, hậu tố lớn nhất/nhỏ nhất, 
tổng đoạn con và tổng đoạn con lớn nhất/nhỏ nhất. Sau đó ta cập nhật giá trị từ u->LCA(u, v) và v->LCA(u, v). Lưu ý là đoạn từ u->LCA(u, v)
được tính từ trái sang phải và đoạn v->LCA(u, v) được tính từ phải sang trái nên ta cần đảo lại giá trị tiền tố và hậu tố đoạn 
từ v->LCA(u, v).
*/

struct info
{
    ll sum, minpref, maxpref, minsuff, maxsuff, minseg, maxseg;
    info()
    {
        sum=minpref=minsuff=minseg=maxpref=maxsuff=maxseg=0;
    }
    info (ll _n)
    {
        sum=_n;
        minpref=minsuff=minseg=min(0LL, _n);
        maxpref=maxsuff=maxseg=max(0LL, _n);
    }
};

info merges(const info &a, const info &b)
{
    info ans;
    ans.sum=a.sum+b.sum;
    ans.minpref=min(a.minpref, a.sum+b.minpref);
    ans.maxpref=max(a.maxpref, a.sum+b.maxpref);
    ans.minsuff=min(b.minsuff, b.sum+a.minsuff);
    ans.maxsuff=min(b.maxsuff, b.sum+a.maxsuff);
    ans.minseg=min({a.minseg, b.minseg, a.minsuff+b.minpref});
    ans.maxseg=max({a.maxseg, b.maxseg, a.maxsuff+b.maxpref});
    return ans;
}

ll n, par[200005][25], d[200005];
info val[200005][25];

void solve()
{
    cin>>n;
    val[1][0]=info(1);
    d[1]=0;
    ll sz=1;
    for (ll k=1; k<=n; k++)
    {
        char type; 
        cin>>type;
        if (type=='+')
        {
            ++sz;
            ll u, x; cin>>u>>x;
            par[sz][0]=u;
            val[sz][0]=info(x);
            d[sz]=d[u]+1;
            for (ll i=1; i<=20; i++) 
                par[sz][i]=par[par[sz][i-1]][i-1];
            for (ll i=1; i<=20; i++) 
                val[sz][i]=merges(val[sz][i-1], val[par[sz][i-1]][i-1]);
        }
        else 
        {
            ll u, v, k; cin>>u>>v>>k;
            if (d[u]<d[v]) swap(u, v);
            ll diff=d[u]-d[v];   
            info a, b;
            for (ll i=0; i<20; i++) 
                if (diff&(1LL<<i)) 
                {
                    a=merges(a, val[u][i]);
                    u=par[u][i];
                }
            if (u==v)
            {
                a=merges(a, val[u][0]);
            }
            else 
            {
                for (ll i=19; i>=0; i--) if (par[u][i]!=par[v][i])
                {
                    a=merges(a, val[u][i]);
                    b=merges(b, val[v][i]);
                    u=par[u][i];
                    v=par[v][i];
                }
                a=merges(a, val[u][1]);
                b=merges(b, val[v][0]);
            }
            ll minseg=min({a.minseg, b.minseg, a.minsuff+b.minsuff});
            ll maxseg=max({a.maxseg, b.maxseg, a.maxsuff+b.maxsuff});
            if (minseg<=k && k<=maxseg) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    for (ll i=0; i<=n; i++)
    {
        for (ll j=0; j<=20; j++)
        {
            par[i][j]=0;
            val[i][j]=info(0);
        }
        d[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}