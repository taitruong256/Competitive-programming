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
Có n con thuyền ở điểm từ 1 đến n và m bến cảng ở vị trí x[i] và có giá trị v[i] (đảm bảo luôn có bến cảng đầu tiên là 1 và cuối cùng là n).
Chi phí để duy chuyển một con thuyền về bến là tích của giá trị gần nhất bên trái với khoảng cách bến cảng gần nhất bên phải.
Nếu con thuyền đã ở trong bến thì chi phí là 0.
Có q truy vấn thuộc 1 trong 2 loại:
    -1 pos val: bến cảng ở vị trí pos có giá trị val. Đảm bảo không có bến cảng ở vị trí pos trước truy vấn loại 1.
    -2 l r: in ra tổng chi phí di chuyển các con thuyền từ vị trí l đến vị trí r.

Input
8 3 4
1 3 8
3 24 10
2 2 5
1 5 15
2 5 5
2 7 8
Output
171
0
15

Ý tưởng:
Bài này cách làm tương tự bài https://cses.fi/problemset/task/1736/ trên CSES
Gọi prv là bến cảng gần nhất bên trái, nxt là bến cảng gần nhất bên phải.
Thay vì cập nhật bậc thang từ trái sang phải thì ta cập nhật từ phải sang trái. Để làm được chỉ cần khởi tạo điểm i với giá trị a[prv]*(nxt-i).
Khi cập nhật bậc thang thì mỗi điểm i trong đoạn [l, r] ta cộng với a[i]*(n-i+1)*val, trừ (n-i)*v với mỗi i trong đoạn [l, r].
Hai việc này có thể thực hiện với segment tree lazy. 
Đầu tiên khởi tạo chi phí cho mỗi chiếc thuyền.
-Với truy vấn loại 1:   
    Trừ (pos-prv)*v[prv] với mỗi i trong đoạn [prv+1, pos].
    Trừ (nxt-i)*v[pre] với mỗi i trong đoạn [pos+1, nxt-1].
    Cộng (nxt-i)*val với mỗi i trong đoạn [pos+1, nxt-1].
-Với truy vấn loại 2:
    In ra tổng trong đoạn [l, r].
*/

ll n, m, q, x[300005], v[300005];

struct segment_tree_lazy
{
    vector<ll> tree, lazy1, lazy2;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy1.resize(4*n+5);     //lazy1 cộng (l-1)*a đoạn [l, r]
        lazy2.resize(4*n+5);     //lazy2 cộng v[i]*(n-i+1) đoạn [l, r]
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    ll f(ll l, ll r)
    {
        return r*(r+1)/2-(l-1)*l/2;
    }

    void down(ll id, ll l, ll r)
    {
        ll mid=(l+r)/2;

        tree[id*2]+=lazy1[id]*(mid-l+1);
        lazy1[id*2]+=lazy1[id];
        tree[id*2+1]+=lazy1[id]*(r-mid);
        lazy1[id*2+1]+=lazy1[id];
        lazy1[id]=0;

        tree[id*2]+=lazy2[id]*f(n-mid+1, n-l+1);
        lazy2[id*2]+=lazy2[id];
        tree[id*2+1]+=lazy2[id]*f(n-r+1, n-mid);
        lazy2[id*2+1]+=lazy2[id];
        lazy2[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val1, ll val2)
    {
        if (l>r || l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val1*(r-l+1)+val2*f(n-r+1, n-l+1);
            lazy1[id]+=val1;
            lazy2[id]+=val2;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val1, val2);
        update(id*2+1, mid+1, r, u, v, val1, val2);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=m; i++) cin>>x[i];
    for (ll i=1; i<=m; i++) cin>>v[x[i]];
    segment_tree_lazy seg(n);
    set<ll> st;
    for (ll i=1; i<=m; i++) st.insert(x[i]);
    for (ll i=1; i<=n; i++)
    {
        auto it=st.lower_bound(i);
        if (*it==i) continue;
        ll prv=*prev(it), nxt=*it;
        seg.update(1, 1, n, i, i, -(n-i)*v[prv]*(nxt-i), v[prv]*(nxt-i));
    }
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll pos, val; cin>>pos>>val;
            v[pos]=val;
            auto it=st.lower_bound(pos);
            ll prv=*prev(it), nxt=*it;
            seg.update(1, 1, n, prv+1, pos, -(nxt-pos)*v[prv], 0);
            seg.update(1, 1, n, pos+1, nxt-1, v[prv]*(n-nxt+1), -v[prv]);
            seg.update(1, 1, n, pos+1, nxt-1, -v[pos]*(n-nxt+1), v[pos]);
            st.insert(pos);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query(1, 1, n, l, r)<<endl;
        }
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