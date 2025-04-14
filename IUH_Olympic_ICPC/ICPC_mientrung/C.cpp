#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

int ans = 0;

void cal(map<int,int> mp) {
      if(mp.size() == 0) return ;
    for(auto p: mp) {
        cout<<p.first<<" "<<p.second<<" "<<binpow(2, p.second, MOD) -1<<endl;

        ans+=((binpow(2, p.second, MOD)-1+MOD))%MOD*p.first%MOD;
        ans%=MOD;
    }
    vector<pair<int,int>> res;
    for(auto p: mp) {
        res.push_back({p.first, p.second});
    }
    int n = res.size(); 
    // cout<<n<<endl;
    mp.clear();
    for(int i =n-1; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            mp[gcd(res[i].first, res[j].first)]+=res[i].second*res[j].second;
        }
    }
   
    cal(mp);
}

void solve() {
    int n;
    cin >> n;
    int a[n+5];
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        // ans+=a[i];
        // ans%=MOD;
    }
    sort(a+1, a+1+n);
    for(int i=n-1; i>=1; i--) {
        map<int,int> mp;
        cout<< i<<"___________"<<endl;
        for(int j=i+1; j<=n; j++) {
            mp[gcd(a[i], a[j])]++;
        }
        // for(auto p: mp) {
        //     ans+=((binpow(2, p.second, MOD)-1+MOD))%MOD*p.first%MOD;
        //     ans%=MOD;
        // }
        cal(mp);
        mp.clear();
    }
    cout<< ans<<'\n';

}
/*
1 21
2 5
3 2
4 1
9 1
10 1
60
*/
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
     solve();
    return 0;
}