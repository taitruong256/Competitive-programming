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
Cây nhị phân hoàn chỉnh là cây mà mỗi nút ngoài lá có chính xác 2 con trái và phải.
Mỗi cạnh cây nhị phân có trọng số 0 và 1. Bạn quên mất cây như thế nào nhưng lại nhớ mảng khoảng cách từ gốc đến đỉnh i là a[i].
Hỏi có tồn tại cây nhị phân có khoảng cách từ gốc tới các lá hay không?
Thứ tự của cây dfs như sau:
dfs_order = []

function dfs(v):
    if v is leaf:
        append v to the back of dfs_order
    else:
        dfs(left child of v)
        dfs(right child of v)

dfs(root)

Input
2
5
2 1 0 1 1
5
1 0 2 1 3

Ý tưởng:
Nếu 2 nút lá chung cha sẽ có trọng số chênh lệch nhau là 1 và sẽ nằm kề nhau trong thứ tự dfs. Khi xóa 2 nút lá chung cha, 
nút cha đó sẽ trở thành nút lá mới.
Ta sẽ ưu tiên xóa nút có khoảng cách lớn nhất (vì giữ nó lại không giúp tìm các nút lá mới trong tương lai).
Dùng priority queue để duy trì những nút được chọn để xóa và có khoảng cách đến gốc lớn nhất và mảng prv, nxt để lưu danh
sách liên kết tới phần tử liền trước và liền sau.
*/

ll n, a[200005], vis[200005], prv[200005], nxt[200005];

bool check(ll i)
{
    if (i==0 || i==n+1) return false;
    if (a[prv[i]]==a[i]-1 || a[i]-1==a[nxt[i]]) return true;
    return false;
}

void solve()
{
    ll mx=0;
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) prv[i]=i-1, nxt[i]=i+1,  mx=max(mx, a[i]), vis[i]=false;
    a[0]=a[n+1]=-2;
    priority_queue<pair<ll, ll>> pq;
    for (ll i=1; i<=n; i++) if (check(i)==true) pq.push({a[i], i}), vis[i]=true;
    while (!pq.empty())
    {
        auto [x, y]=pq.top(); pq.pop();
        prv[nxt[y]]=prv[y];
            nxt[prv[y]]=nxt[y];
        if (check(prv[y])==true && vis[prv[y]]==false) 
        {
            pq.push({a[prv[y]], prv[y]});
            vis[prv[y]]=true;
        }
        if (check(nxt[y])==true && vis[nxt[y]]==false) 
        {
            pq.push({a[nxt[y]], nxt[y]});
            vis[nxt[y]]=true;
        }
    }

    ll mn=1e18, v=0;
    for (ll i=1; i<=n; i++) mn=min(mn, a[i]), v+=vis[i], vis[i]=false;
    if (mn==0 && v==n-1) cout<<"YES\n";    //còn lại một đỉnh gốc không xóa và phải có một đỉnh có khoảng cách tới gốc là 0.
    else cout<<"NO\n";
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