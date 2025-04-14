#include <bits/stdc++.h>
using namespace std;
constexpr int N = 60010, M = 9;
constexpr int mask = 255;
int n, K, a[N], f[10][N], g[1 << M][1 << M];
int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] ^= a[i - 1];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= K; i++)
    {
        memset(g, 0x3f, sizeof(g));
        for (int j = 1; j <= n; j++)
        {
            for (int t = 0; t <= mask; t++)
            {
                int d = (t ^ (a[j - 1] >> 8)) << 8;
                g[t][a[j - 1] & mask] = min(g[t][a[j - 1] & mask], f[i - 1][j - 1] + d);
            }
            for (int t = 0; t <= mask; t++)
                f[i][j] = min(f[i][j], g[a[j] >> 8][t] + ((a[j] ^ t) & mask));
        }
    }
    for (int i = K; i <= n; i++)
        cout << f[K][i] << " ";
}