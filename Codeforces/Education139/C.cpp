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
string s[3]; 

void loang_truoc(ll x, ll y)
{        
    if (y==0) return;
    if (s[x][y]=='W') return;
    if (s[x][y]==s[3-x][y]) 
    {
        s[x][y]='W';
        loang_truoc(3-x, y);
    }
    else if (s[x][y]==s[x][y-1] || s[x][y-1]==' ') 
    {
        s[x][y]='W';
        loang_truoc(x, y-1);
    }
}

void loang_sau(ll x, ll y)
{            
    if (y==0) return;
    if (s[x][y]=='W') return;
    if (s[x][y]==s[3-x][y]) 
    {
        s[x][y]='W';
        loang_sau(3-x, y);
    }
    else if (s[x][y]==s[x][y+1] || s[x][y+1]==' ') 
    {
        s[x][y]='W';
        loang_sau(x, y+1);
    }
}

void solve()
{
    ll n; cin>>n;
    cin>>s[1]>>s[2];
    s[1]=" "+s[1]+" ";
    s[2]=" "+s[2]+" ";
    ll x=1, y=1;
    for (ll i=1; i<=n; i++) if (s[1][i]=='W' || s[2][i]=='W') 
    {
        y=i;
        if (s[1][i]=='W') x=2;
        else x=1;
        break;
    }
    loang_truoc(x, y);
    s[x][y]='B';
    loang_sau(x, y);
    for (ll i=1; i<=n; i++) if (s[1][i]=='B' || s[2][i]=='B')
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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