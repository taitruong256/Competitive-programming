//私はあなたがいなくて寂しいです
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define double long double
using namespace std;
void debug_out() {cout << endl;}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)


vector<int> base[26];
void solve() {
    int n; cin >>n;
    // cout<<n<<'\n';
    int ans = 0;
    for(int i=24; i>=0; i--) {
        for(int j =4; j>=1; j--) {
            if(base[i][j] > n) continue;
            n -= base[i][j];
            ans +=  j*base[i][0];
        }
    }
    cout<<ans<<'\n';
    
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tmp = 1;
    int cur = 0;
    for(int i=0; i<25; i++) {
        tmp*=5;
        base[i].push_back(tmp);
        for(int j = 1; j<5; j++) {
            base[i].push_back(cur*j + j);
        }
        cur += tmp;
    }
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int T=1;
    cin >> T;
    while(T--) {
        solve();
    }
}
//1906