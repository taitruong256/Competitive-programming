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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Cho một cây n đỉnh n-1 cạnh, mỗi đỉnh có giá trị a[i].
Gọi g(u, v) là phép OR của tất cả các số trên đường đi từ u đến v.
Gọi độ tốt của z là tổng bit 1 của g(u, z) + tổng bit 1 của g(v, z)
Có q truy vấn, mỗi truy vẫn cho hai số x và y, hãy tìm độ tốt lớn nhất của z nằm trên đường đi từ u đến v.

Input
3
7
4 7 7 4 10 8 10
6 1
3 1
2 1
7 4
1 5
4 2
4
7 5
2 3
4 5
2 5
6
9 5 6 2 4 6
5 1
2 1
1 6
4 3
1 3
4
6 1
1 4
4 3
3 5
7
5 1 3 7 5 1 6
2 1
5 4
2 3
3 4
7 6
6 3
2
4 2
7 7
Output
8 6 7 7 
6 6 4 7 
6 4 

Note
https://espresso.codeforces.com/6593c65ccba073343a949513539f66051b09099e.png

Trong truy vấn đầu tiên, chúng ta có x=7, y=5. Đường đi ngắn nhất từ 7 đến 5 là 7−4−2−1−5.

Hãy tính độ đẹp của đỉnh 7 trên con đường này. Chúng ta có g(7,7)=a7=10=(1010)2 
và g(5,7)=a5 | a1 | a2 | a4 | a7=10 | 4 | 7 | 4 | 10=15=(1111)2, vậy độ đẹp của nó bằng 2+4=6.

Bây giờ hãy tính độ đẹp của đỉnh 4 trên con đường này. Chúng ta có g(7,4)=a7 | a4=10 | 4=14=(1110)2 
và g(5,4)=a5 | a1 | a2 | a4=10 | 4 | 7 | 4=15=(1111)2, vậy độ đẹp của nó bằng 3+4=7.

Bây giờ hãy tính độ đẹp của đỉnh 2 trên con đường này. Chúng ta có g(7,2)=a7 | a4 | a2=10 | 4 | 7=15=(1111)2 
và g(5,2)=a5 | a1 | a2=10 | 4 | 7=15=(1111)2, vậy độ đẹp của nó bằng 4+4=8.

Bây giờ hãy tính độ đẹp của đỉnh 1 trên con đường này. Chúng ta có g(7,1)=a7 | a4 | a2 | a1=10 | 4 | 7 | 4=15=(1111)2
và g(5,1)=a5 | a1=10 | 4=14=(1110)2, vậy độ đẹp của nó bằng 4+3=7.

Cuối cùng hãy tính độ đẹp của đỉnh 5 trên con đường này. Chúng ta có g(7,5)=a7 | a4 | a2 | a1 | a5=10 | 4 | 7 | 4 | 10=15=(1111)2
và g(5,5)=a5=10=(1010)2, vậy độ đẹp của nó bằng 4+2=6.

Độ đẹp tối đa trên đường dẫn này là ở đỉnh 2, và nó là 8.

Ý tưởng
Nhận xét: có 2.log(max(A)) ứng viên trên đường đi ngắn nhất từ u đến v. Bởi vì đường đi từ u->v có thể tách thành u->LCA(u, v)
và v->LCA(u, v). Mà có tối đa log(max(A)) bit có thể thêm vào g(u, z) và chúng ta muốn tối đa số bit 1 của g(u, z)+g(z, v). 
Tất cả các đỉnh khác sẽ không đóng góp gì cho sum OR ngoài z vì vậy ta không cần xem xét chúng.

Với mỗi bit 0 ở vị trí i của u, ta sẽ tìm đỉnh z có bit 1 ở vị trí i sao cho z gần u nhất trên đường đi từ đến v.
Để tìm được, ta đặt gốc là 1, dùng mảng pre[u][i] là số đỉnh có bit 1 ở vị trí i trên đường đi từ root=1 đến u.
Dễ dàng tính số bit 1 trên đường đi từ u đến v là pre[u][i]+pre[v][i]-2*pre[LCA(u, v)][i]+bit[i] của LCA(u, v). 
Dùng nâng nhị phân tương tự tìm LCA để tìm vị trí bit 1 gần nhất với đỉnh u. Sau khi đã tìm được các ứng viên, cập nhật lại
đáp án theo từng ứng viên. Làm tương tự với đường đi từ LCA(u, v)->v.

*/

ll n, q, a[200005];
vector<ll> adj[200005];
ll par[200005][20], val[200005][32], dis[200005], pre[200005][32];

void dfs(ll u, ll p)
{
    dis[u]=dis[p]+1;
    par[u][0]=p;
    val[u][0]=a[u];
    for (ll i=0; i<32; i++) if (a[u]&(1LL<<i)) ++pre[u][i];
    for (ll i=1; i<20; i++) 
    {
        par[u][i]=par[par[u][i-1]][i-1];
        if (par[u][i-1]!=0) val[u][i]=(val[u][i-1]|val[par[u][i-1]][i-1]);
    }

    for (ll v: adj[u]) if (v!=p)
    {
        for (ll i=0; i<32; i++) pre[v][i]+=pre[u][i];
        dfs(v, u);
    }
}

ll LCA(ll u, ll v)
{
    if (dis[u]<dis[v]) swap(u, v);
    for (ll i=19; i>=0; i--) if ((dis[u]-dis[v])&(1LL<<i)) u=par[u][i];
    if (u==v) return u;
    for (ll i=19; i>=0; i--) if (par[u][i]!=par[v][i]) 
    {
        u=par[u][i];
        v=par[v][i];
    }
    return par[u][0];
}

ll query_or(ll u, ll v)
{
    ll l=LCA(u, v), ans=0;
    for (ll i=19; i>=0; i--) if (dis[u]-(1LL<<i)+1>=dis[l]) ans|=val[u][i], u=par[u][i];
    for (ll i=19; i>=0; i--) if (dis[v]-(1LL<<i)+1>=dis[l]) ans|=val[v][i], v=par[v][i];
    return ans;
}

ll query_bit(ll u, ll v, ll i)
{
    ll l=LCA(u, v);
    return pre[u][i]+pre[v][i]-2*pre[l][i]+((a[l]&(1LL<<i))>0);
}

ll query(ll u, ll v)
{
    vector<ll> cand;
    cand.push_back(u);
    cand.push_back(v);
    ll l=LCA(u, v), ans=0;
    for (ll i=0; i<32; i++) if (!(a[u]&(1LL<<i)))
    {
        ll node=u;
        for (ll j=19; j>=0; j--) if ((1LL<<j)<=dis[node]-dis[l] && query_bit(par[node][j], node, i)==0)
            node=par[node][j];
        if (node!=l) cand.push_back(par[node][0]);
    }
    for (ll i=0; i<32; i++) if (!(a[v]&(1LL<<i)))
    {
        ll node=v;
        for (ll j=19; j>=0; j--) if ((1LL<<j)<=dis[node]-dis[l] && query_bit(par[node][j], node, i)==0)
            node=par[node][j];
        if (node!=l) cand.push_back(par[node][0]);
    }
    for (auto i: cand) ans=max(ans, (ll)__builtin_popcount(query_or(u, i))+__builtin_popcount(query_or(v, i)));
    // for (auto i: cand) cout<<i<<" "; cout<<endl;
    return ans;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cin>>q;
    while (q--)
    {
        ll u, v; cin>>u>>v; 
        cout<<query(u, v)<<" ";
    }
    cout<<endl;
    for (ll i=1; i<=n; i++)
    {
        adj[i].clear();
        dis[i]=0;
        for (ll j=0; j<20; j++) par[i][j]=0;
        for (ll j=0; j<32; j++) val[i][j]=pre[i][j]=0;
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