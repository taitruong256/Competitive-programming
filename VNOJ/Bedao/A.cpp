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
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;





struct line {
    int l, r, val;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    vector<line> get;
    vector<line> up[q+5];
    for(int i=1; i<=q; i++){
        int type; cin >> type;
        if(type ==1) {
            int l, r, x;
            cin >>l >> r >>x;
            up[cnt].push_back({l, r, x});
        }
        else {
            int l, r; cin >> l >> r;
            get.push_back({l, r});
            cnt++;
        }
    }
    for(int i=0; i<get.size(); i++) {
        int ans =0;
        for(line res : up[i]) {
               int d = max(-max(res.l, get[i].l) + min(res.r, get[i].r)+1, 0);
            //    cout<<d<<endl;
               if(d%2) {
                    // cout<<res.val<<"help"<<endl;
                    ans^= res.val;
               } 
        }
        cout<< ans<<'\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}