#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int long long
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    int n; cin >> n;
    char a[n+5];
    for(int i=1; i<=n; i++) cin >> a[i];
    int m = 1, l = 1, cnt = 0;
    pair<char,int> b[n+5];

    for(int i=1; i<=n; i++) {
        if(a[i] == a[l]) cnt++;
        else {
            b[m++] = {a[l], cnt};
            l = i;
            cnt = 1;
        }
    }
    b[m] = {a[n], cnt};
    vector<int> pref(m+5);
    for(int i=1; i<=m; i++) pref[i] = b[i].second*b[i].second + pref[i-1];
    int ans = pref[m];
    
    for(int i=2; i<=m; i++) {
        int l = i-1;
        int r = i;
        if(b[i].second)    
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}