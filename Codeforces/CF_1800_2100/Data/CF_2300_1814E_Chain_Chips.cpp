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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

/*
Bạn được cho một đồ thị vô hướng gồm n đỉnh và n-1 các cạnh. Cạnh thứ i có trọng số ai; nó kết nối các đỉnh i và i+1.
Ban đầu, mỗi đỉnh chứa một con chip. Mỗi con chip có một số nguyên được ghi trên đó; số nguyên được ghi trên chip trong đỉnh thứ i là i..

Trong một thao tác, bạn có thể chọn một con chip (nếu có nhiều con chip ở một đỉnh, bạn có thể chọn bất kỳ con chip nào trong số chúng) 
và di chuyển nó dọc theo một trong các cạnh của biểu đồ. Chi phí của hoạt động này bằng với trọng lượng của cạnh.
Chi phí của biểu đồ là chi phí tối thiểu của một chuỗi các hoạt động đó đáp ứng điều kiện sau:
    Sau khi tất cả các thao tác được thực hiện, mỗi đỉnh chứa chính xác một chip và số nguyên trên mỗi chip không bằng chỉ số của đỉnh nơi đặt chip đó.
Bạn được tặng q truy vấn có dạng (k x): - thay đổi trọng số cạnh thứ k (cạnh nối các đỉnh k và k+1) đến x.
Sau mỗi truy vấn, in chi phí của biểu đồ. Lưu ý rằng bạn không thực sự di chuyển bất kỳ con chip nào; khi bạn tính toán chi phí, các con chip sẽ ở vị trí ban đầu.

10
12 6 12 15 20 8 17 12 15
8
4 10
7 3
6 14
9 9
2 10
3 5
4 11
7 11

Ý tưởng:
Đối với mỗi cạnh, số lần nó đi qua phải là số chẵn vì mỗi con chip cần đi tới và đi ngược lại.
Đối với mỗi đỉnh, ít nhất một cạnh tới được đỉnh đó phải được duyệt ít nhất 2 lần, nếu không chip tử đỉnh này không thể di chuyển sang bất cứ đỉnh khác.
Chúng ta muốn đi qua các cạnh càng ít càng tốt, hóa ra mỗi cạnh được chọn sẽ được duyệt qua chính xác 2 lần. Hãy chia đồ thị
thành nhiều phần bằng cách loại bỏ các cạnh không đi qua, không phá vỡ ràng buộc mỗi đỉnh có ít nhất một cạnh thì mỗi phần sẽ chứa ít nhất hai đỉnh.
Trong mỗi phần, ta duyệt qua mỗi cạnh 2 lần như sau: gọi đoạn đó là [l, r], thì con chip r sẽ di chuyển đến vị trí l, l di chuyển đến vị trí l+1, l+1 di
chuyển đến vị trí l+2, ... r-1 đến vị trí r. thì mọi cạnh trong đoạn sẽ được duyệt chính xác 2 lần.

Bây giờ bài toán trở thành như sau: chọn một tập hợp con các cạnh sao cho mỗi đỉnh có ít nhất một cạnh được chọn, giảm thiểu tổng trọng số của tập hợp con này 
và in số nguyên gấp đôi tổng trọng số đó.
Chúng ta có thể sử dụng dp[i][f]: tổng trọng lượng tối thiểu của tập hợp con trong đoạn [1..i] và f=0 nếu cạnh thứ i không được chọn và ngược lại. Tuy nhiên
cách này hoạt động trong O(n.q).
Có một cách để lưu dp trong cây phân đoạn, mỗi nút của cây phân đoạn ta sẽ lưu mảng data[f1][f2] 2x2 biểu thị giá trị nhỏ nhất
của tổng tập hợp con đoạn [l, r], f1 và f2 tương ứng trạng thái cạnh đầu tiên/cuối cùng của đoạn [l, r] có được chọn hay không?

Lưu ý là dùng mảng tĩnh thay vì dùng vector vì nó sẽ nhanh hơn.
*/

ll n, q, a[200005];

struct node
{
    ll data[2][2];
    node()
    {
        data[0][0]=data[0][1]=data[1][0]=data[1][1]=1e18;
    }

    node operator + (const node &other)
    {
        node ans;
        for (ll i=0; i<2; i++)
            for (ll j=0; j<2; j++)
                for (ll k=0; k<2; k++)
                    for (ll l=0; l<2; l++)
                        if (j+k>0)         //khi kết hợp hai đoạn, ít nhất phải có một cạnh (cạnh cuối cùng của đoạn bên trái hoặc cạnh đầu tiên đoạn bên phải) được sử dụng. Tức là không có hai cạnh không được sử dụng liên tiếp.
                            ans.data[i][l]=min(ans.data[i][l], this->data[i][j]+other.data[k][l]);
        return ans;
    }
};

struct segment_tree
{
    vector<node> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            node nd;
            nd.data[0][0]=0;
            nd.data[1][1]=a[l];
            tree[id]=nd;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l==r) 
        {
            node nd;
            nd.data[0][0]=0;
            nd.data[1][1]=v;
            tree[id]=nd;
            return;
        }
        ll mid=(l+r)/2;
        if (pos<=mid) update(id*2, l, mid, pos, v);
        else update(id*2+1, mid+1, r, pos, v);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};

void solve()
{
    cin>>n;
    --n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree seg(n);
    seg.build(1, 1, n);
    cin>>q;
    while (q--)
    {
        ll pos, val; cin>>pos>>val;
        seg.update(1, 1, n, pos, val);
        cout<<2*seg.tree[1].data[1][1]<<endl;
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