/*=====================================================================================
                Nothing is impossible, only you think it is impossible
                        Try, try, try again until you succeed
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m, vt = 1,x,y;
    cin >> n >> m;
    int arr[n+1],b[n+1];
    bool check[n+1];
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 2; i < n; i++) {
        if (arr[i-1] > arr[i] && arr[i] < arr[i+1])
            check[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = vt;
        if (check[i]) vt = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x<b[y]) puts("No");
        else puts("Yes");
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

