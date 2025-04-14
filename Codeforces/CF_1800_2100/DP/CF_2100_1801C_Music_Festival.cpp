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
Có n album, album thứ i có k[i] bài hát, bài hát thứ j có độ hay là album[i][j].
Độ ấn tượng là số bài hát hay hơn tất cả bài hát trước đó. Hãy sắp sếp các album sao cho độ ấn tượng là lớn nhất.
(Các bài hát trong album không được thay đổi thứ tự).

Input
2
4
5
4 9 4 6 8
1
7
2
8 6
1
1
4
2
3 4
2
1 8
2
2 8
2
7 9
Output
4
4

Note
In the first test example, the optimal order is listening to the 4th, 2nd, 3rd and 1st albums.
In this case, Masha will listen to the tracks in the following order: _1, _7, _8, 6, 4, _9, 4, 6, 8 (_ tính là 1) and will receive 4 units of impression

Ý tưởng:
Đầu tiên ta cần nén các bài hát trong album lại, ví dụ [1,4,4,3,6,5,6] sẽ thành [1,4,6]
Ta sẽ thực hiện dp trên các album đã nén.
Thực hiện lưu chỉ mục với từng bài hát c của album i.
Gọi dp[i] là độ ấn tượng lớn nhất của album[i].
Duyệt các bài hát có độ hay c theo thứ tự tăng dần:
    Nếu c là bắt đầu của album[i]:
        dp[i]=max(dp[1..n])+1       //độ hay lớn nhất của những album[j] bài hát kết thúc < c. Và c duyệt theo thứ tự tăng dần nên đảm bảo c > max(album[1..n])
    Ngược lại:
        dp[i]=max(dp[i]+1, max(dp[1..n])+1)    //lưu ý là sau khi nén album[i] sẽ tăng ngặt. Có thể thêm bài c vào album[i] hoặc thêm c vào album[1..n] có bài hát kết thúc < c
    Có thể dùng biến end_album để lưu độ ấn tượng lớn nhất của các bài hát <=c.
*/

void solve()
{
    ll n; cin>>n;
    vector<ll> album[n+5];
    for (ll i=1; i<=n; i++)
    {
        ll k; cin>>k;
        for (ll j=1; j<=k; j++)
        {
            ll x; cin>>x;
            album[i].push_back(x);
        }
        vector<ll> v;
        for (ll x: album[i]) if (v.empty() || x>v.back()) v.push_back(x);
        album[i]=v;
    }             

    vector<ll> dp(n+5);
    map<ll, vector<ll>> val;
    for (ll i=1; i<=n; i++)
        for (ll x: album[i])
            val[x].push_back(i);
    
    ll end_album=0;
    for (auto [c, v]: val)
    {
        ll new_end_album=0;
        for (ll i: v) 
        {
            if (c==album[i].front()) 
                dp[i]=end_album+1;
            else
                dp[i]=max(dp[i]+1, end_album+1);
            if (c==album[i].back()) new_end_album=max(new_end_album, dp[i]);
        }
        end_album=max(end_album, new_end_album);
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
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