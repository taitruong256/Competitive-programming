#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = (b-a+1)*(d-c+1);    
    
    int mx = max(b, d);
    for(int i=2; i<=d; i++) {
        int L = 0;
        int R = 0;
        for(int j=i; j<=d; j+=i) {
            if(j>=a &&j<=b) L++;
            if(j<=d && j>=c) R++;
        }
        
        ans -= L*R;
    }
   
    cout<<ans<<'\n';
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}