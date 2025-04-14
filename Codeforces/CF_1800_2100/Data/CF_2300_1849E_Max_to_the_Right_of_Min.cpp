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
Cho hoán vị độ dài n. Đếm số đoạn [l, r] thỏa mãn vị trí giá trị lớn nhất > vị trí giá trị nhỏ nhất trong đoạn [l, r].

Input
6
5 3 6 1 4 2
Output
4

Note:
Các đoạn là [1, 3], [2, 3], [4, 5], [4, 6].

Ý tưởng:
Xét tất cả đoạn [l, r] với r cố định. Khi di chuyến l từ phải qua trái ta thấy giá trị nhỏ nhất càng nhỏ và giá trị lớn nhất càng lớn.
Chúng ta có thể duy trì cả hai giá trị bằng stack đơn điệu.
Xét hai sự kiện liên tiếp (idx1, t1) và (idx2, t2) - idx là chỉ số của sự kiện, t=0 là giá trị cực tiểu và t=1 là giá trị cực đại.
Khi t2=0 thì tất cả giá trị l trong đoạn [idx1+1, idx2] thõa mãn.
Để triển khai, chúng ta dùng set<pair<idx, t>> để duy trì sự kiện của các cực đại/cực tiểu tại vị trí idx đồng thời duy trì khoảng cách 
từ sự kiện 0 cuối cùng tới sự kiện 1 liền trước đó.
    -Khi chúng ta xóa sự kiện, các khoảng cách bị thay đổi là sự kiện tiếp theo đến hiện tại, sự kiện hiện tại đến sự kiện trước đó,
    sự kiện tiếp theo đến sự kiện trước đó.
    -Khi thêm vào sự kiện, chỉ cần thêm nó vào cuối tập hợp.
*/

ll n, a[1000005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    vector<pair<ll, ll>> stkmin, stkmax;
    set<pair<ll, ll>> st;
    ll len=0, ans=0;
    stkmin.push_back({0, 0});
    stkmax.push_back({n+1, 0});
    st.insert({0, 0});
    st.insert({0, 1});
    for (ll i=1; i<=n; i++)
    {
        while (stkmin.back().first>a[i]) 
        {
            auto it=st.lower_bound({stkmin.back().second, 0});
            auto prv=prev(it);
            auto nxt=next(it);
            len-=it->first-prv->first;
            if (nxt!=st.end() && nxt->second==0) 
                len+=nxt->first-prv->first;
            stkmin.pop_back();
            st.erase(it);
        }
        stkmin.push_back({a[i], i});
        st.insert({i, 0});
        len+=1;

        while (stkmax.back().first<a[i])
        {
            auto it=st.lower_bound({stkmax.back().second, 1});
            auto prv=prev(it);
            auto nxt=next(it);
            if (nxt!=st.end() && nxt->second==0) 
                len+=it->first-prv->first;
            stkmax.pop_back();
            st.erase(it);
        }
        stkmax.push_back({a[i], i});
        st.insert({i, 1});
        ans+=len;
        // cerr<<"stkmin:  "; for (auto [x, y]: stkmin) cerr<<x<<" "<<y<<"    "; cerr<<endl;
        // cerr<<"stkmax:  "; for (auto [x, y]: stkmax) cerr<<x<<" "<<y<<"    "; cerr<<endl;
        // cerr<<"st    :  "; for (auto [x, y]: st    ) cerr<<x<<" "<<y<<"    "; cerr<<endl;
        // cerr<<"len:     "<<len<<endl<<endl;
    }
    cout<<ans-n;
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