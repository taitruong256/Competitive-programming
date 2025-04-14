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
Cho n điểm có tọa độ (x, y) riêng biệt và đường thẳng x+y=k. 
Bạn có thể thực hiện 1 trong 2 thao tác:
    -Chọn hai số a và b thỏa a+b<k, tất cả các điểm trong tam giác x=a, y=b và a+b=k sẽ xóa. Gọi l là độ dài tam giác cân l, l, l.sqrt(2)
    thì chi phí là l.A
    -Xóa một điểm cụ thể chi phí c[i].
Hỏi chi phí tối thiểu để xóa tất cả các điểm là bao nhiêu.

Input
6 7 1
4 2 1
3 3 1
5 1 4
3 2 5
4 1 1
0 6 4
Output
4

Note:
https://espresso.codeforces.com/7dcb47025d0a1e126ca510fda9e4d5a3f5af07e1.png

Ý tưởng:
Tất cả các tam giác sẽ rời nhau, nếu không rời nhau ta sẽ hợp lại chi phí thấp hơn. (vì khi có phần giao mà không hợp lại thì chi phí là l1*A + l2*A, 
mà hợp lại thì chi phí là l1+l2-giao(l1, l2)*A).
Gọi [L, R] biểu diễn tam giác có các góc (L, k-L) và (R, k-R).
Giả sử tất cả các điểm đều tạo ra chi phí. 
Gọi f(L, R) là biểu diễn tổng chi phí các điểm trong tam giác [L, R] - A(R-L). Chúng ta cần tìm một số đoạn [l1, r1], [l2, r2], ..., [lm, rm] không có 
phần chung và min(sum(f(li, ri)))
Gọi dp[i] là biểu diễn giá trị min(sum(f(li, ri))) trong tiền tố [1..i]. Có hai trạng thái chuyển đổi:
    -Nếu i không được chọn, dp[i]=dp[i-1]
    -Nếu i được chọn để bao phủ đoạn [j+1, i], dp[i]=min(dp[j]+f(j+1, i))               dp[i]=min(dp[j]+f(j+1, i))=min(dp[j]+i*A-j*A+sumcost[j+1..i])
Ta sẽ dùng segment tree lazy cộng đoạn x và tìm min, duy trì g[j]=dp[j]+f(j+1, i).
*/

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return min(x, y);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        tree[id*2]+=t;
        lazy[id*2]+=t;
        tree[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e18;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

ll n, k, A, dp[200005], sum;
vector<pair<ll, ll>> pos[200005];

void solve()
{
    cin>>n>>k>>A;
    for (ll i=1; i<=n; i++)
    {
        ll x, y, c; cin>>x>>y>>c;
        pos[k-y].push_back({x, c});
        sum+=c;
    }
    segment_tree_lazy seg(k+1);
    for (ll i=1; i<=k; i++)
    {
        for (auto [x, c]: pos[i]) 
            seg.update(1, 0, k, 0, x, -c);       //đoạn [0..x] không ảnh hưởng bởi chi phí điểm j. khúc này hơi lú.
        seg.update(1, 0, k, 0, i-1, A);          //cộng thêm A đoạn [0..i].
        dp[i]=min(dp[i-1], seg.query(1, 0, k, 0, i-1)); 
        seg.update(1, 0, k, i, i, dp[i]);
    }
    cout<<sum+dp[k];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}