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
Cho mảng a n phần tử, thực hiện các bước sau:
1. Sắp sếp mảng tăng dần, xóa phần tử trùng lặp
2. Nếu mảng chỉ còn duy nhất 1 phần tử, xuất ra số đó
3. Cộng phần tử a[i] thêm n-i, chỉ số bắt đầu từ 0 và n là số phần tử của mảng hiện tại
4. Lặp lại bước 1.
Có q truy vấn, mỗi truy vấn cập nhật a[p]=x, tìm kết quả của thao tác trên.

Input
4
3
2 4 8
3
1 6
2 10
3 1
5
1 2 2 2 2
1
5 3
2
5 6
7
1 2
1 7
1 7
2 5
1 2
2 7
2 2
5
2 5 1 10 6
10
1 7
4 8
2 5
1 4
2 8
3 4
1 9
3 7
3 4
3 1
Output
10 12 15 
4 
10 8 8 9 8 12 2 
14 12 12 11 11 10 11 10 11 14 

Hãy xem xét ví dụ đầu tiên về đầu vào.

Ban đầu, dãy số được đưa vào làm đầu vào cho thiết bị sẽ là [6,4,8]. Nó sẽ thay đổi như sau:
[6,4,8]→[4,6,8]→[7,8,9]→[10,10,10]→[10]
Khi đó, dãy số được cung cấp làm đầu vào cho thiết bị sẽ là [6,10,8]. Nó sẽ thay đổi như sau:
[6,10,8]→[6,8,10]→[9,10,11]→[12,12,12]→[12]
Mảng số cuối cùng được đưa vào làm đầu vào cho thiết bị sẽ là [6,10,1]. Nó sẽ thay đổi như sau:
[6,10,1]→[1,6,10]→[4,8,11]→[7,10,12]→[10,12,13]→[13,14,14]→[13 ,14]→[15,15]→[15]

Ý tưởng:
Câu trả lời chính là số lớn nhất + chênh lệch giữa hai phần tử liền kề khi sắp sếp lớn nhất.
Để duy trì số lớn nhất ta dùng multiset ms
Để duy trì chênh lệch giữa hai phần tử lớn nhất khi sắp sếp ta dùng multiset diff. Khi thay thế một số, 
ta sẽ loại bỏ số cũ và thay thế chênh lệch mới với các số lân cận. 
*/

ll n, q, a[200005];
multiset<ll> ms, diff;

void del(ll val)
{
    auto it=ms.find(val);
    if (it!=ms.begin()) diff.erase(diff.find(*it-*prev(it)));
    if (next(it)!=ms.end()) diff.erase(diff.find(*next(it)-*it));
    if (it!=ms.begin() && next(it)!=ms.end()) diff.insert(*next(it)-*prev(it));
    ms.erase(it);
}

void add(ll val)
{
    auto it=ms.insert(val);
    if (it!=ms.begin()) diff.insert(*it-*prev(it));
    if (next(it)!=ms.end()) diff.insert(*next(it)-*it);
    if (it!=ms.begin() && next(it)!=ms.end()) diff.erase(diff.find(*next(it)-*prev(it)));
}

void solve()
{
    diff.insert(0);
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) ms.insert(a[i]);
    for (auto it=ms.begin(); it!=ms.end(); it++) if (it!=ms.begin()) diff.insert(*it-*prev(it));
    cin>>q;
    while (q--)
    {
        ll p, x; cin>>p>>x;
        del(a[p]);
        a[p]=x;
        add(a[p]);
        cout<<*ms.rbegin()+*diff.rbegin()<<" ";
    }
    cout<<endl;
    ms.clear();
    diff.clear();
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