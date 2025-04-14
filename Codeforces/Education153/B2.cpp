#include<bits/stdc++.h>
#define ll long long
#define int ll
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define show cerr<<"*\n"
using namespace std;
void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(_VA_ARGS_)

const int INF =1e9+7;

void solve() {
    int n, k, a1, ak; cin >> n>> k >>a1 >> ak;
    int used_k = n/k;
    int ans=INF;
    for(used_k; used_k>=0; used_k--) {
        int res = max(used_k-ak, 0ll);

//        debug(res);
        res+=max(n-used_k*k-a1,0ll);
        if(res<ans) ans=res;
        else break;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
}