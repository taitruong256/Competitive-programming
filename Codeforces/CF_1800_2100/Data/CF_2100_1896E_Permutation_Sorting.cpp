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
Cho một hoán vị độ dài n. Vị trí i được gọi là tốt nếu a[i]=i
Mỗi giây hoán vị sẽ xoay phải như sau:
    -Gọi s1, s2, ... sk là vị trí không tốt tăng dần.
    -Mỗi i (1<=i<=k) gán a[s[i%k+1]]=a[s[i]]
Hỏi với mỗi i từ 1 đến n, a[i]=i sau mấy lần xoay (tính lần đầu tiên)

Input
2
5
3 2 4 1 5
6
2 1 4 6 5 3
Output
1 0 1 1 0 
2 1 2 1 0 1 

Ghi chú
Trong trường hợp thử nghiệm đầu tiên, 2 và 5 đã ở đúng vị trí nên chỉ số 2 và 5 trở nên tốt ở mức 0. 
Sau 1 giây, một sự dịch chuyển theo chu kỳ sẽ được thực hiện với s=[1,3,4], dẫn đến mảng a=[1,2,3,4,5]. Lưu ý rằng chỉ số 1, 3 và 4 trở nên tốt 1 giây.

Trong trường hợp thử nghiệm thứ hai, 5 đã ở đúng vị trí nên chỉ số 5 trở nên tốt ở mức 0 giây. 
Sau 1 giây, một sự thay đổi theo chu kỳ sẽ được thực hiện với s=[1,2,3,4,6], dẫn đến mảng a=[3,2,1,4,5,6]. Chú ý rằng chỉ số 2, 4 và 6 trở nên tốt 1 giây. 
Sau 2 giây, một sự dịch chuyển theo chu kỳ sẽ được thực hiện với s=[1,3], dẫn đến mảng a=[1,2,3,4,5,6]. Lưu ý rằng chỉ số 1 và 3 trở nên tốt ở 2 giây.

Ý tưởng:
Vì mảng tuần hoàn nên ta sẽ lưu mảng a độ dài 2*n, mỗi i (n+1<=i<=2*n), a[i]=a[i-n].
Gọi h[i] là số lần xoay phải để a[i]=i:
    h[i]=a[i]-i nếu i<=a[i]
    h[i]=a[i]+n-i nếu i>a[i]
Đáp án ans[i]=h[i] - những số nằm trong đoạn (i, i+h[i]) mà i<a[j]<i+h[i]. Vì những số a[i]=i sẽ bị loại khi tới vòng xoay tiếp theo
Để tính ta sẽ xử lý offline bằng cách lưu mảng pair<pos, a[j]>, ta sẽ duyệt từ 2n đến 1, mỗi lần sẽ tính đáp án và tăng a[j] lên 1.
*/

struct fenwick
{
    ll n; 
    vector<ll> bit;

    void init(ll _n)
    {
        n=_n;
        bit.resize(0);
        bit.resize(2*n+5);  //lưu ý mảng độ dài 2*n
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=2*n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};
fenwick ft;
ll n, a[2000005], ans[2000005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=n+1; i<=n; i++) a[i]=a[i-n];
    vector<pair<ll, ll>> v;
    for (ll i=1; i<=n; i++)
    {
        if (i<=a[i]) v.push_back({i, a[i]}), v.push_back({i+n, a[i]+n});
        else v.push_back({i, a[i]+n});
    }
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    ft.init(n);
    for (auto [l, r]: v)
    {
        ans[a[l]]=r-l-ft.query(l, r);
        ft.update(r, 1);
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
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