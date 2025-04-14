#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD =  998244353;

int n; 
string h; 
int dp[N][63][2][2][2];


int aqua(int i, int j, bool so, bool hoa, bool thuong) {
    if(i==n) {
        if(so && hoa && thuong) return 1;
        return 0;
    }

    if(j!=-1&&dp[i][j][so][hoa][thuong]!=-1) return dp[i][j][so][hoa][thuong];


    int ans = 0;
    if(h[i]=='?') {
        for(int c=0; c<62; c++) {
            bool socur = so, hoacur = hoa, thuongcur = thuong;
            if(c!=j) {
                if(c<=9&&c>=0) socur=true;
                else if(c>=10&&c<=35) thuongcur = true;
                else hoacur= true;
                ans+=aqua(i+1, c, socur, hoacur, thuongcur);
                if (ans >= MOD) ans -= MOD;
            } 
        }
    }
    else if(h[i] <='z' &&h[i]>='a') {
        bool socur = so, hoacur = hoa, thuongcur = thuong;
        int c = h[i]-'a';
        c+=10;
        thuongcur = true;
        if(c!=j) ans+=aqua(i+1, c, socur, hoacur, thuongcur);
        if (ans >= MOD) ans -= MOD;
        c +=26;
        socur = so, hoacur = hoa, thuongcur = thuong;
        hoacur = true;
        if(c!=j) ans+=aqua(i+1, c, socur, hoacur, thuongcur);
        if (ans >= MOD) ans -= MOD;
    }
    else {
        bool socur = so, hoacur = hoa, thuongcur = thuong;
        int c = 0;
        if(h[i]<='9'&&h[i]>='0') { 
            c=h[i]-'0';
            socur = true;
            if(c!=j) {
                ans+=aqua(i+1,c, socur, hoacur, thuongcur);
                if (ans >= MOD) ans -= MOD;
            }
        }
        else {
            c=h[i]-'A';
            c+=36;
            hoacur = true;
            if(c!=j) {
                ans+=aqua(i+1, c, socur, hoacur, thuongcur);
                if (ans >= MOD) ans -= MOD;
            }
        }

    }
    return dp[i][j][so][hoa][thuong] = ans;
}



void solve() {
    cin >> n;
    cin >> h;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<63; j++) {
            for(int k = 0; k<2; k++) {
                for(int e =0; e<2; e++) {
                    for(int f = 0; f<2; f++)
                        dp[i][j][k][e][f] = -1;
                }
            }
        }
    }

    cout<<aqua(0, -1, false, false, false);
    // cout<<dp[0][1][0][0]<<'\n';
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}