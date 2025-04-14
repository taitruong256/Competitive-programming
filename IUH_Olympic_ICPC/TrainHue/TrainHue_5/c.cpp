/*=====================================================================================
                Nothing is impossible, only you think it is impossible
                        Try, try, try again until you succeed
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long arr[200006];
long long dequy(long long n, long long k) {
    if (k==1) return n;
    if (k==0) return 1;
    if (n==2 && (k==2 || k==3)) return 1;
 return dequy(n-1, (k-1)%arr[n-1]);
}

void solve()
{
    long long n, k;
    cin >> n >> k;

    arr[1] = 1;
    for (ll i = 2; i <= n; i++) {
        arr[i] = arr[i-1]*2+1;
    }
   // cout<<arr[n]<<endl;
    if (k>arr[n]) {
        cout << -1;
        return;
    }
    if (n>=10) {
    string s="1";
    for(ll i=2;i<=n;i++){
        string g= to_string(i);
        s=g+s+s;
    }
    cout << s[k-1];
    }
    else cout << dequy(n,k);
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
