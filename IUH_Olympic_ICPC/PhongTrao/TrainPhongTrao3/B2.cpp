#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n, m,vt = 0;
    cin >> n >> m;
    int a[n+1];
    for (int i = 0; i< n; i++){
        cin >> a[i];
    }
    while (m--) {
        if (a[vt]>0) a[vt]--;
        else {
            vt++;
            if(vt==n-1) break;
            a[vt]--;
        }
        a[n-1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}