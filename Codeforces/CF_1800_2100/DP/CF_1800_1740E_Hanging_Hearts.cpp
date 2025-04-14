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
Cho một cây n đỉnh, n-1 cạnh, gốc là 1. Bạn được chọn một hoán vị độ dài n ghi trên mỗi đỉnh.
Ban đầu tập s ban đầu rỗng:
Thực hiện n thao tác:
    -Chọn đỉnh x sao cho x không có con
    -Thêm x vào tập s
    -Nếu x!=1, và a[p[x]]>a[x], thì gán a[p[x]]=a[x], ngược lại không làm gì.
    -Xóa đỉnh x.
Hỏi độ dài chuỗi con không giảm dài nhất của s là bao nhiêu?

Input
6
1 2 1 4 2
Output
4

Pak Chanek can choose the permutation a=[1,5,4,3,2,6].
Let wi be the number written on card i. Initially, wi=ai. 
Pak Chanek can do the following operations in order:

Select card 5. Append w5=2 to the end of s. As w4>w5, the value of w4 becomes 2. Remove card 5. After this operation, s=[2].
Select card 6. Append w6=6 to the end of s. As w2≤w6, the value of w2 is left unchanged. Remove card 6. After this operation, s=[2,6].
Select card 4. Append w4=2 to the end of s. As w1≤w4, the value of w1 is left unchanged. Remove card 4. After this operation, s=[2,6,2].
Select card 3. Append w3=4 to the end of s. As w2>w3, the value of w2 becomes 4. Remove card 3. After this operation, s=[2,6,2,4].
Select card 2. Append w2=4 to the end of s. As w1≤w2, the value of w1 is left unchanged. Remove card 2. After this operation, s=[2,6,2,4,4].
Select card 1. Append w1=1 to the end of s. Remove card 1. After this operation, s=[2,6,2,4,4,1].
One of the longest non-decreasing subsequences of s=[2,6,2,4,4,1] is [2,2,4,4]. 
Thus, the length of the longest non-decreasing subsequence of s is 4
. It can be proven that this is indeed the maximum possible length.

Ý tưởng:
Giá trị đỉnh u sẽ là giá trị nhỏ nhất trong cây con gốc u.
Gọi dp[u] là độ dài dãy con tăng dài nhất của cây con gốc u.
    -Nếu chọn đỉnh u, dp[u] sẽ là độ dài lớn nhất của cây con.
    -Nếu không chọn đỉnh u, dp[u] sẽ là tổng dp[v] với v là con trực tiếp của u.
*/

ll n, dp[100005], maxdepth[100005];
vector<ll> adj[100005];

void dfs(ll u, ll p=0)
{
    for (ll v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        maxdepth[u]=max(maxdepth[u], maxdepth[v]);
        dp[u]+=dp[v];
    }
    ++maxdepth[u];
    dp[u]=max(dp[u], maxdepth[u]);
}

void solve()
{
    cin>>n;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    cout<<dp[1];
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