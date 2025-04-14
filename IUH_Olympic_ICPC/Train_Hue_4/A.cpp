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
    int n, m;
    long long group, sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        sum += i;
        if (sum >= n) {
            sum -= i;
            group = i;
            break;
        }
    }
    int arr[2][group+5];
    arr[0][1] = 1;
    arr[1][1] = 1;
    for (int i = 2; i < group; i++) {
        m = (arr[1][i-1]/i+1)*i;
        arr[0][i] = m;
        arr[1][i] = m + (i-1)*i;
    }
    m = (arr[1][group-1]/group +1)*group;
    arr[0][group] = m;
    cout << m + (n-sum-1)*group;
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