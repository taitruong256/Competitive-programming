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
Có n thùng nước, mỗi thùng nước i ban đầu có a[i] lít nước, có thể tạo tối đa b[i] lít rượu.
Ngoài ra còn có n-1 van nước từ thùng i đến thùng i+1 có sức chứa c[i] (phiên bản dễ c[i]=1e18).
Có q truy vấn, mỗi truy vấn (p, x, y, z) 
    Cập nhật a[p]=x, b[p]]=y, c[p]=z.
    Thực hiện thao tác sau i từ 1 đến n:
        +Biến tối đa b[i] lít nước trong thùng i thành rượu.
        +Nếu i<n, lượng nước còn lại sẽ chảy qua thùng i+1 với sức chứa tối đa c[i] (phiên bản dễ c[i]=1e18).
    Hỏi có bao nhiêu lít rượu được tạo ra.

Input
5 5
10 3 8 9 2
3 4 10 8 1
1000000000000000000 1000000000000000000 1000000000000000000 1000000000000000000
5 4 9 1000000000000000000
1 1 1 1000000000000000000
2 7 4 1000000000000000000
4 1 1 1000000000000000000
1 8 3 1000000000000000000
34
25
29
21
27

Ý tưởng:
Vì tất cả c[i]=1e18 nên toàn bộ lượng nước còn lại của thùng thứ i sẽ chảy qua thùng i+1.
Đáp án sẽ là sum(a)-lượng nước còn lại.
Nhiệm vụ là tính lượng nước còn lại mỗi truy vấn => là max(suff[i]=sum(a[i..n]-b[i..n])) (nghĩa là tổng lượng nước trừ đi 
giới hạn có thể tạo ra rượu, nếu <=0 nghĩa là không có lượng nước dư), phải dùng suffix vì nước ở thùng i chỉ chảy ra sau.
Dùng segment tree lazy max sum để cập nhật nhanh thay đổi.
*/

ll n, q, a[500005], b[500005], c[500005], sum=0;

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
        return max(x, y);
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
        if (l>v || r<u) return 0;
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

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    for (ll i=1; i<=n-1; i++) cin>>c[i];
    segment_tree_lazy seg(n);
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, 1, i, a[i]-b[i]), sum+=a[i];
    while (q--)
    {
        ll p, x, y, z; cin>>p>>x>>y>>z;
        sum-=a[p];
        seg.update(1, 1, n, 1, p, -(a[p]-b[p]));
        a[p]=x;
        b[p]=y;
        c[p]=z;
        sum+=a[p];
        seg.update(1, 1, n, 1, p, a[p]-b[p]);
        cout<<sum-max(0LL, seg.query(1, 1, n, 1, n))<<endl;
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}