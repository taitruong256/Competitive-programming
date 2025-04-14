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

void solve()
{
    ll n, m; cin>>n>>m;
    char c[n+5][m+5];
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=m+1; j++) c[i][j]='.';
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>c[i][j];

    ll cnt=0;
    bool check=true;
    for (ll i=1; i<=n; i++)
    {
        cnt=0;
        for (ll j=1; j<=m; j++) 
            if (c[i][j]!='.') ++cnt;
        if (cnt%2==1) check=false;
                                                
        cnt=0;
    }                                     

    for (ll j=1; j<=m; j++)
    {
        cnt=0;
        for (ll i=1; i<=n; i++) 
            if (c[i][j]!='.') ++cnt;
        if (cnt%2==1) check=false;      
        cnt=0;
    }                                   

    if (check==false)
    {
        cout<<-1<<endl;
        return;
    }

    for (ll i=1; i<=n; i++)
    {
        ll inv=0;=
        for (ll j=1; j<=m; j++) if (c[i][j]=='U')
        {
            if (inv==0)
            {
                c[i][j]='B';
                c[i+1][j]='W';
            }
            else 
            {
                c[i][j]='W';
                c[i+1][j]='B';
            }
            inv=1-inv;
        }
    }

    for (ll j=1; j<=m; j++)
    {
        ll inv=0;
        for (ll i=1; i<=n; i++) if (c[i][j]=='L')
        {
            if (inv==0)
            {
                c[i][j]='B';
                c[i][j+1]='W';
            }
            else 
            {
                c[i][j]='W';
                c[i][j+1]='B';
            }
            inv=1-inv;
        }
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) cout<<c[i][j];
        cout<<endl;
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}