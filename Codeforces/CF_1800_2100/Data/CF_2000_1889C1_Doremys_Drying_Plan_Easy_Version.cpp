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
ll n, m, k, cnt[200005];
vector<ll> ADD[200005], DEL[200005];

/*
Có n điểm từ 1 đến n và m đoạn [l, r].
Hỏi sau khi xóa chính xác 2 đoạn thì số điểm không được bao phủ bởi bất kỳ đoạn nào lớn nhất là bao nhiêu.

Input
6
2 3 2
1 2
1 2
1 1
5 3 2
1 3
2 4
3 5
10 6 2
1 5
6 10
2 2
3 7
5 8
1 4
100 6 2
1 100
1 100
1 100
1 100
1 100
1 100
1000 2 2
1 1
1 1
20 5 2
9 20
3 3
10 11
11 13
6 18
Output
1
2
3
0
1000
15

Ý tưởng:
Đầu tiên chúng ta có thể tính mỗi điểm i có bao nhiêu đoạn thẳng che phủ bằng cách thêm đoạn thẳng x vào thời điểm l 
và xóa đoạn thẳng x vào thời điểm r+1.
Gọi số điểm không được bảo phủ bởi bất kỳ đoạn thẳng nào là A và số điểm mới không được bao phủ sau khi xóa chính xác 2 đoạn
thẳng là B. Đáp án sẽ là A+max(B)
Để tính B, ta sẽ xét hai đoạn thẳng I1 và I2:
    -Nếu I1 và I2 không giao nhau, thì B = số vị trí được bao phủ bởi chính xác một đoạn là I1 + số vị trí được bao phủ bởi chính xác một đoạn là I2.
    -Nếu I1 và I2 giao nhau, thì B = số vị trí được bao phủ bởi chính xác một đoạn là I1 + số vị trí được bao phủ bởi chính xác một đoạn là I2 + số vị 
    trí được bao phủ bởi chính xác hai đoạn I1 và I2.
Tuy nhiên phương án duyệt trâu sẽ có độ phức tạp là O(n+m^2)
Để cải tiến:
    -Nếu I1 và I2 không giao nhau, ta chỉ cần chọn hai đoạn sao cho nó có số điểm được bao phủ chính xác một đoạn là nhiều nhất.
    -Nếu I1 và I2 giao nhau, thì sẽ có nhiều nhất là n cặp hữu ích (có n điểm được bao phủ bởi chính xác 2 đoạn). Vì vậy ta sẽ
    duyệt qua n điểm, gọi hai đoạn thẳng bao phủ điểm đó là x và y thì ta sẽ cập nhật lại đáp án là res=max(res, cnt[x] + cnt[y] + số điểm được bao phủ bởi x và y).
    Ở đây cnt[x] và cnt[y] lần lượt là số vị trí được bao phủ bởi chính xác một đoạn là x + số vị trí được bao phủ bởi chính xác một đoạn là y. Ta sẽ dùng map 
    để đếm số điểm được bao phủ bởi x và y.
*/

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=m; i++)
    {
        ll l, r; cin>>l>>r;
        ADD[l].push_back(i);
        DEL[r+1].push_back(i);
    }
    set<ll> seg;
    ll ans=0;
    map<pair<ll, ll>, ll> mp;
    for (ll i=1; i<=n; i++)
    {
        for (auto x: ADD[i]) seg.insert(x);
        for (auto x: DEL[i]) seg.erase(x);
        if (seg.size()==0) ++ans;
        else if (seg.size()==1) ++cnt[*seg.begin()];
        else if (seg.size()==2)
        {
            ll x=*seg.begin(), y=*seg.rbegin();
            ++mp[{x, y}];
        }
    }
    vector<ll> v;
    v.push_back(0);
    v.push_back(0);
    for (ll i=1; i<=m; i++) v.push_back(cnt[i]);
    sort(v.begin(), v.end(), greater<ll>());
    ll res=v[0]+v[1];                                     
    for (auto [x, y]: mp) res=max(res, cnt[x.first]+cnt[x.second]+y);
    cout<<ans+res<<endl;
    for (ll i=1; i<=n+1; i++) ADD[i].clear(), DEL[i].clear();
    for (ll i=1; i<=m; i++) cnt[i]=0;   
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