#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, k, a, m, u;
    cin >> n >> k >> a;
    cin >> m;
    set<int> st;
    st.insert({0, n+1});
    vector<int> a1(n+2), a2(n+2);
    for (int i = 1; i <= m; i++) 
    {
        cin >> u;
        st.insert(u);        
        auto it = lower_bound(st.begin(), st.end(), u);
        it--;
        for (; it!=st.end(); it++) {
            auto tmp = ++it;
            --it;
            a1[*tmp] = a1[*it] + (*tmp - *it - 1)/a;
        }
        auto it2 = upper_bound(st.begin(), st.end(), u);
        for (;;it2--) {
            auto tmp = --it2;
            ++it2;
            a2[*tmp] = a2[*it2] + (*it2 - *tmp - 1)/a;
        }
        for (auto _ = st.begin(); _!=st.end(); _++) {
            if (a1[*_] + a2[*_] < k) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
}