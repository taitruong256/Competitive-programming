/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1001
bool check[N][N];
bool kt1(int i, int j) {
    int count  = 0;
    if (check[i-1][j]==1 && i>0) count++;
    if (check[i][j+1]==1) count++;
    if (check[i+1][j]==1) count++;
    if (check[i][j-1]==1 && j>0) count++;
    if (count==3) return 1;
    return 0;
}
bool kt2(int i, int j) {
    int count  = 0;
    if (check[i-1][j]==1 && i>0) count++;
    if (check[i][j+1]==1) count++;
    if (check[i+1][j]==1 && i) count++;
    if (check[i][j-1]==1 && j>0) count++;
    if (count==4) return 1;
    return 0;
}
void solve()
{
    int n, count = 0;
    cin >> n;
    pair<int,int> p[n+1];
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < n; i++) {
        check[p[i].first][p[i].second] = 1;
        if (kt1(p[i].first, p[i].second)) count++;
        if (kt1(p[i].first+1, p[i].second)) count++;
        if (kt1(p[i].first, p[i].second-1)) count++;
        if (kt1(p[i].first, p[i].second+1)) count++;
        if (kt1(p[i].first-1, p[i].second)) count++;
        if (kt2(p[i].first+1, p[i].second)) count--;
        if (kt2(p[i].first, p[i].second-1)) count--;
        if (kt2(p[i].first, p[i].second+1)) count--;
        if (kt2(p[i].first-1, p[i].second)) count--;
        cout << count << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}