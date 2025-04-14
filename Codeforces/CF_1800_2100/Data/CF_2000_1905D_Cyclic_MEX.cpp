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
Cho mảng hoán vị p có n phần tử, chi phí của mảng là sum(mex(p[1..i]))
Tìm chi phí của mảng hoán vị lớn nhất khi xoay.

Input
4
6
5 4 3 2 1 0
3
2 1 0
8
2 3 6 7 0 1 4 5
1
0
Output
15
5
31
1

Note
In the first test case, the cyclic shift that yields the maximum cost is [2,1,0,5,4,3] with cost 0+0+3+3+3+6=15.
In the second test case, the cyclic shift that yields the maximum cost is [0,2,1] with cost 1+1+3=5.

Ý tưởng:
Hãy phân tích xem giá trị của từng tiền tố mex thay đổi như thế nào khi thực hiện dịch chuyển theo chu kỳ sang trái:

    -Tiền tố mex đầu tiên được bật lên.
    -Mỗi tiền tố mex có giá trị nhỏ hơn p1 không thay đổi.
    -Mỗi tiền tố mex có giá trị lớn hơn p1 trở thành p1.
    -N được gắn vào phía sau.
Hãy nén các mex tiền tố của chúng ta (có nghĩa là chúng ta giữ giá trị và tần số của nó thay vì giữ nhiều giá trị giống nhau). 
Sau đó, chúng ta có thể mô phỏng quá trình trên một cách đơn giản bằng deque, vì điện thế sẽ giảm theo số lượng thao tác được thực hiện.

Giải pháp này hoạt động trong O(n) thời gian.
*/

void solve()
{
    ll n; cin>>n;
    ll a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    deque<pair<ll, ll>> dq;
    ll mex=0, ans=0, sum=0;
    vector<ll> f(n+5);
    for (ll i=1; i<=n; i++)
    {
        ++f[a[i]];
        while (f[mex]==1) ++mex;
        dq.push_back({mex, 1});
        sum+=mex;
    }
    // for (auto [x, y]: dq) cout<<x<<" "<<y<<"   "; cout<<endl;
    ans=sum;
    for (ll i=1; i<n; i++) 
    {
        --dq.front().second;
        sum-=dq.front().first;
        if (dq.front().second==0) dq.pop_front();
        pair<ll, ll> cur={a[i], 0};
        while (!dq.empty() && dq.back().first>=a[i])
        {
            cur.second+=dq.back().second;
            sum-=dq.back().first*dq.back().second;
            dq.pop_back();
        }
        dq.push_back(cur);
        sum+=dq.back().first*dq.back().second;
        dq.push_back({n, 1});
        sum+=n;
        ans=max(ans, sum);
        // for (auto [x, y]: dq) cout<<x<<" "<<y<<"   "; cout<<endl;
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