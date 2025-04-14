#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[1001];
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    int m=-10000;
    for (int i=2; i<n; i++) m=max(m, a[i]-a[i-2]);
    cout<<m;
    return 0;
}

