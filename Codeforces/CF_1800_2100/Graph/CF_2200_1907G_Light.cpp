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
Có n bòng đèn và n công tắc, công tắc thứ i sẽ thay đổi trạng thái (bật sang tắt, tắt sang bật) bóng đèn thứ i và a[i].
Hãy tìm số lần sử dụng công tắc ít nhất để tắt tất cả bóng đèn.

Input
8
5
11101
4 3 4 2 2
2
10
2 1
10
0000000011
9 10 10 7 10 9 9 9 10 2
10
1000111101
9 3 8 9 2 1 3 7 2 7
10
0001101010
5 7 6 10 8 3 6 6 2 2
10
0101100010
8 7 7 9 9 4 1 4 2 7
10
1010111010
7 9 10 7 7 2 8 6 10 4
10
1110000001
3 10 10 1 10 8 6 3 2 1
Output
3
1 5 3 
-1
1
9 
5
5 6 10 2 3 
6
4 9 5 10 8 7 
3
5 4 9 
6
1 3 5 9 7 8 
2
2 1 

Ý tưởng:
Xây dựng đồ thị có hướng từ đỉnh i đến a[i]. 
Đầu tiên ta sẽ tắt tất cả bóng đèn không thuộc chu trình:
    -Loại bỏ các đỉnh có bóng đèn tắt nếu không có đỉnh đi vào
    -Tắt bóng đèn đang bật, loại bỏ nó nếu không có đỉnh đi vào
Còn lại các bóng đèn trong chu trình, nếu số bóng đèn là lẻ thì sẽ không có đáp án.
Ngược lại, ta sẽ đếm số thao tác tuần tự.
Lưu ý, nếu trường hợp trạng thái bóng đèn trong chu trình là 10000000001011 thì xuất phát bóng đèn đầu tiên sẽ không tối ưu, 
ta sẽ cần xét thêm trường hợp xuất phát từ bóng đèn không phải bóng đèn đầu tiên trong chu trình. 
(vì hai bóng đèn sáng liền kề sẽ triệt tiêu lẫn nhau)
*/

ll n, a[200005], deg[200005], s[200005];
string st;
vector<ll> ans;

void solve()
{
    cin>>n;
    ans.clear();
    for (ll i=1; i<=n; i++) deg[i]=0;
    cin>>st; st=" "+st;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        ++deg[a[i]];
        s[i]=st[i]-'0';
    }
    queue<ll> q;
    for (ll i=1; i<=n; i++) if (deg[i]==0) q.push(i);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();  
        ll v=a[u];       
        if (s[u]==1) 
        {
            s[u]=!s[u];
            s[v]=!s[v];
            ans.push_back(u);
        } 
        --deg[v];
        if (deg[v]==0) q.push(v);
    }

    vector<ll> vis(n+5, false);
    for (ll i=1; i<=n; i++) if (vis[i]==false && s[i]==1)
    {
        vector<ll> cycle, light;
        ll u=i, sum=0;
        while (vis[u]==false) 
        {
            vis[u]=true;
            cycle.push_back(u);
            light.push_back(s[u]);
            sum+=s[u];
            u=a[u];
        }
        cycle.push_back(u);
        light.push_back(s[u]);
        if (sum%2==1)
        {
            ans.clear();
            cout<<-1<<endl;
            return;
        }

        vector<ll> cand1, val1=light;
        for (ll j=0; j<(ll)cycle.size()-1; j++) if (val1[j]==1) 
        {
            val1[j]=1-val1[j];
            val1[j+1]=1-val1[j+1];
            cand1.push_back(cycle[j]);
        }

        vector<ll> cand2, val2=light;
        for (ll j=1; j<(ll)cycle.size()-1; j++) if (val2[j]==1) 
        {
            val2[j]=1-val2[j];
            val2[j+1]=1-val2[j+1];
            cand2.push_back(cycle[j]);
        }

        if ((ll)cand1.size()<=(ll)cand2.size()) 
            for (auto x: cand1) ans.push_back(x);
        else 
            for (auto x: cand2) ans.push_back(x);
    }
    cout<<ans.size()<<endl;
    for (auto x: ans) cout<<x<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}