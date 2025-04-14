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
Cho ma trận n hàng m cột. Mỗi cột, ô từ 1 đến a[i] là màu đen, a[i]+1 đến n là màu trắng.
Bạn cần đặt m số nguyên vào ma trận sao cho:
    -Mỗi ô chứa nhiều nhất một số nguyên
    -Ô màu đen không được chứa số nguyên nào.
Độ đẹp của ma trận là số lượng số nguyên j sao cho số nguyên j+1 nằm trên cùng một hàng.
Tìm độ đẹp lớn nhất.

Input
6
3
0 0 0
9
4
2 0 3 1
5
4
2 0 3 1
6
4
2 0 3 1
10
10
0 2 2 1 5 10 3 4 1 1
20
1
1
0
Output
6
3
4
4
16
0

Ý tưởng:
Ta sẽ đặt các số nguyên trên hàng có đoạn màu trắng dài nhất có số lượng k thì đáp án sẽ cộng thêm k-1.
Vì vậy đáp án sẽ là sum(k[i]-1), mà tổng k[i]=m nên sum(k[i]-1)=m-s. Vậy đáp án sẽ là m-số đoạn màu trắng ít nhất để lấp đầy m số nguyên.
Để tìm số đoạn ít nhất, ta chỉ cần chọn đoạn dài nhất. Tuy nhiên số đoạn có thể lên đến n^2. 
Vì các đoạn có độ dài từ 1 đến n nên ta có thể nén, đếm số lượng độ dài của mỗi đoạn.

Duyệt các hàng từ dưới lên trên, có một số cột màu đen sẽ chia một đoạn màu trắng thành hai đoạn bên trái và bên phải
Chúng ta sẽ lưu các đoạn màu trắng trong mỗi hàng từ dưới lên tồn tại trong khoảng thời gian từ nào? Khi biết thời gian
cuối cùng tồn tại của đoạn [l, r], ta chỉ cần từ đi thời gian của sự kiện hiện tại. 

Dùng map<pair<ll, ll>, ll> timer để lưu thời gian cuối cùng tồn tại của các đoạn màu trắng của các hàng theo thứ tự từ dưới lên.
Nó sẽ hỗ trợ:
    Tìm một đoạn bao phủ ô x.
    Xóa một đoạn.
    Thêm một đoạn.
Tạo sự kiện các cột (a[i], i), sắp sếp theo thứ tự giảm dần của a[i]. Với mỗi sự kiện, tìm đoạn mà cột màu đen sẽ tách ra,
lưu thông tin đoạn đó và thêm thông tin của hai đoạn mới bị tách ra.

Cuối cùng, để tìm số đoạn ít nhất bao phủ m số nguyên, chỉ cần duyệt các đoạn độ dài từ lớn đến nhỏ, lắp chúng vào khi có thể 
(lưu ý là tổng độ dài có thể lớn hơn m chứ không nhất thiết phải chính xác bằng m nên không cần dp).
*/

void solve()
{
    ll n; cin>>n;
    vector<ll> cnt(n+5);
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].first, a[i].second=i;
    sort(a+1, a+n+1, greater<pair<ll, ll>>());
    map<pair<ll, ll>, ll> timer;
    timer[{1, n}]=n;
    ll j=1;
    for (ll i=n; i>=0; i--)
    {
        while (j<=n && a[j].first==i)
        {
            auto it=timer.upper_bound({a[j].second, n+1});
            it=prev(it);
            auto [l, r]=it->first;  
            cnt[r-l+1]+=it->second-i;
            timer.erase(it);
            if (l!=a[j].second)
                timer[{l, a[j].second-1}]=i;
            if (r!=a[j].second)
                timer[{a[j].second+1, r}]=i;
            ++j;
        }
    }
    ll m; cin>>m;
    ll ans=0;
    for (ll i=n; i>=1; i--)
    {
        ll val=min(m/i, cnt[i]);
        ans+=val*(i-1); 
        m-=val*i;       
        cnt[i]-=val;
        if (m>0 && (m+i-1)/i<=cnt[i]) 
        {
            ans+=m-1;
            m=0;
        }
    }
    cout<<ans<<endl;
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