/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
 
map<string, int> mp;
int n, k;
vector<vector<string>> khach(10);
vector<vector<int>> khach_int(10);
int ans =0;
bool cmp(vector<int> a, vector<int> b) {
    return sz(a) < sz(b);
}

// void tohop(ll n, ll k)
// {
//     ll id[n+5];
//     for (ll i=1; i<=n; i++) id[i]=i;
//     do 
//     {
//         for (ll i=1; i<=k; i++) cout<<id[i]<<" "; cout<<endl;
//     }
//     while (next_permutation(id+1, id+n+1));
// }

void cal(int cnt, int idx, vector<vector<int>> tmp) {
  
    if(cnt ==k) {
        sort(tmp.begin(), tmp.end(), cmp);
        map<int,int> check, dem;
        for(int i=0; i<sz(tmp); i++) {
            for(int j: tmp[i]) {
                dem[j]++;
            }
        }
        int res =0;
        for(int i=0; i<sz(tmp); i++) {
            int value_tmp =0;
            if(sz(tmp[i])<=2) {
                for(int j: tmp[i]) {
                    if(check.count[j]==0)
                }
            }
            for(int j: tmp[i]) {
                // cout<< j<<" ";
                if(check.count(j)==0) {
                    value_tmp += 50;
                    check[j]++;
                }
            }
            // cout<< endl;
            res += min(value_tmp, 114);
        }
        // cout<< "ck"<<endl;
        debug(res);
        ans = max(ans, res);
        // debug(ans);
        return;
    }
   
    for(int i=idx; i<=n; i++) {
        // debug(cnt, i);
        tmp.push_back(khach_int[i]);
        cal(cnt+1, i+1, tmp);
        tmp.pop_back();
    }
}

void solve()
{
    cin >> n >>k;
    // tohop(n, k);
    // cout<< n << " "<<k <<endl;
    for(int i=1; i<=n; i++) {
        int m; cin >> m;
        for(int j=1; j<=m; j++) {
            string res;
            cin >> res;
            khach[i].push_back(res);
            mp[res] = 0;
        }
    }
    int cnt =1;
    for(auto &p: mp) p.second = cnt++;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<sz(khach[i]); j++) {
            // cout<< khach[i][j]<<" "<< mp[khach[i][j]]<<" ";
            khach_int[i].push_back(mp[khach[i][j]]);
        }
        // cout<<endl;
    }
    //  for(int i=1; i<=n; i++) {
    //     for(int j=0; j<sz(khach[i]); j++) {
    //         cout<< khach_int[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    vector<vector<int>> tmp;
    cal(0, 1, tmp);
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t = 1;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}