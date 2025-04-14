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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
vector<vector<ll>> luoi;
ll n, m, a, b, c, d, ans;
string huong;

void loang(ll x, ll y)
{             
    if (x==c && y==d) return;
    if (luoi[x][y]>=10) 
    {
        ans=-1;
        return;
    }
    ++luoi[x][y];

    if (huong[0]=='D' && x+1>n) 
    {
        ++ans, huong[0]='U';
        if (huong[1]=='L' && y-1<1) huong[1]='R';
        if (huong[1]=='R' && y+1>m) huong[1]='L';
    }
    else if (huong[0]=='U' && x-1<1) 
    {
        ++ans, huong[0]='D';
        if (huong[1]=='L' && y-1<1) huong[1]='R';
        if (huong[1]=='R' && y+1>m) huong[1]='L';
    }
    else if (huong[1]=='L' && y-1<1) ++ans, huong[1]='R';
    if (huong[1]=='R' && y+1>m) ++ans, huong[1]='L';
    
    if (huong=="DR") loang(x+1, y+1);
    else if (huong=="DL") loang(x+1, y-1);
    else if (huong=="UR") loang(x-1, y+1);
    else loang(x-1, y-1);
}

void solve()
{
    cin>>n>>m>>a>>b>>c>>d>>huong;
    luoi.resize(n+5);
    for (ll i=0; i<=n+1; i++) 
    {
        luoi[i].resize(m+5);
        luoi[i].assign(m+1, 0);
    }
    ans=0;
    loang(a, b);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}