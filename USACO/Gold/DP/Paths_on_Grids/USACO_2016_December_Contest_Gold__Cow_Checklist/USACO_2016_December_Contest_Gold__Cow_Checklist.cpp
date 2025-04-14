#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long)1e14 + 7;
const int maxn = (int)1e3 + 7;

int n, m;

long long dp[2][maxn][maxn];


long long dist (pair < int, int > a, pair < int, int > b) {
  long long x = a.first - b.first, y = a.second - b.second;
  return x * x + y * y;
}

pair < int, int > a[maxn], b[maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("checklist.in", "r", stdin);
  freopen("checklist.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[0][i][j] = inf;
      dp[1][i][j] = inf;
    }
  }
  dp[0][1][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i > 0 && j > 0) {
        dp[0][i][j] = min(dp[0][i][j], dp[1][i - 1][j] + dist (a[i], b[j]));
        dp[1][i][j] = min(dp[1][i][j], dp[0][i][j - 1] + dist (a[i], b[j]));
      }
      if (i > 0) {
        dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j] + dist (a[i - 1], a[i]));
      }
      if (j > 0) {
        dp[1][i][j] = min(dp[1][i][j], dp[1][i][j - 1] + dist (b[j - 1], b[j]));
      }
    }
  }
  cout << dp[0][n][m];
}