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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

/*
Cho mảng a có n phần tử và q truy vấn [l, r].
Trong mỗi truy vấn, bạn có thể chọn đoạn liên tiếp và trừ tất cả các phần tử trong đoạn với một giá trị không âm.
Mục tiêu là làm cho tất cả các phần tử bằng 0 với mảng có các phần tử ban đầu nằm trong đoạn [l, r]. Hãy in ra số lượng thao tác 
ít nhất. Tuy nhiên không được chọn hai đoạn giao nhau nằm trong nhau.

Input
10 8
1 6 2 3 2 6 3 10 1 2
1 10
2 2
3 3
2 3
1 3
3 6
4 6
5 5
Output
8
1
1
3
5
3
1
0

Ghi chú

Trong trường hợp thử nghiệm đầu tiên
-Hãy xem xét truy vấn thứ hai, khi l=2, r=2. Các phần tử cần thao tác là [a3,a5,a10]=[2,2,2]. Chỉ cần áp dụng chuỗi thao tác {(2,10,2)} là đủ.
-Hãy xem xét truy vấn thứ tư, khi l=2, r=3. Các phần tử cần thao tác là [a3,a4,a5,a7,a10]=[2,3,2,3,2]. Chỉ cần áp dụng chuỗi thao tác {(1,10,2),(4,4,1),(7,7,1)}.

Trong trường hợp thử nghiệm thứ hai, lưu ý rằng chuỗi thao tác {(1,2,1),(2,3,2)} không hợp lệ vì hai đoạn này giao nhau nhưng không nằm trong đoạn kia.
​
Ý tưởng:
Cách tối ưu là chọn toàn bộ mảng, sau đó trừ tất cả phần tử với giá trị nhỏ nhất. Sau đó xử lý với các đoạn bởi số 0.
Hệ quả là hai phần tử bằng nhau liên tiếp không thể có phần tử nhỏ hơn giữa chúng.
Đáp án sẽ là: số phần tử riêng biệt có giá trị ban đầu nằm trong đoạn [l, r] + số phần tử bằng nhau liên tiếp mà giữa chúng có phần tử nhỏ hơn (phần tử này phải nằm trong đoạn [l, r]).
Ta sẽ gọi phần tử lớn nhất giữa hai phần tử bằng nhau liên tiếp là m.
Để tìm chúng, ta sẽ xử lý offine:
    -Sắp sếp các truy vấn theo thứ tự r tăng dần.
    -Dùng 1 cây segment tree để tìm giá trị lớn nhất giữa hai phần tử bằng nhau liên tiếp và cây segment tree để duy trì số lượng của chúng. 
    -Khi tìm được m, ta sẽ cập nhật các truy vấn có giá trị l<=m sẽ tăng thêm một đơn vị (vì r tăng dần, mà các truy vấn có l<=m sẽ thỏa mãn li<=m<=ri<=r)
*/

ll n, q, a[1000005], ans[1000005], distinct[1000005];
vector<ll> pos[1000005];
vector<pair<ll, ll>> qry[1000005];

struct segment_tree_max
{
    vector<ll> tree;
    ll n;

    segment_tree_max(){}
    segment_tree_max(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>r || l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

struct segment_tree_sum
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_sum(){}
    segment_tree_sum(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id], mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        lazy[id*2]+=t;
        tree[id*2+1]+=t*(r-mid);
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>r || l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val*(r-l+1);
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        qry[r].push_back({l, i});
    }

    segment_tree_max segmax(n);
    segment_tree_sum segsum(n);
    for (ll r=1; r<=n; r++)
    {
        distinct[r]=distinct[r-1]+(pos[r].size()>0);
        for (ll i=0; i<sz(pos[r])-1; i++)
        {
            ll x=pos[r][i], y=pos[r][i+1];
            ll mx=segmax.query(1, 1, n, x, y);
            segsum.update(1, 1, n, 1, mx, 1);
        }
        for (ll i: pos[r]) 
            segmax.update(1, 1, n, i, r);
        for (auto [l, i]: qry[r]) 
            ans[i]=distinct[r]-distinct[l-1]+segsum.query(1, 1, n, l, l);
    }

    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
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