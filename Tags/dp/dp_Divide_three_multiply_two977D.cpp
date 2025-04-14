#include <bits/stdc++.h>
using namespace std;
 
pair<long long, long long> a[105];
int cnt(long long x) {
    int res=0;
    while(x%3==0) {
        ++res;
        x/=3;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].first=-cnt(a[i].second);
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) cout << a[i].second << ' ';
}