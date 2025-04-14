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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    char c[10][10];
    ll n=0, m=0;
    for (ll i=0; i<13; i++)
    {
        m=0;
        for (ll j=0; j<13; j++)
        {
            char x; cin>>x;
            if (('0'<=x && x<='9') || x=='.') c[n][m++]=x, cerr<<x<<endl;
        }
        if (i%4!=0) n++;
    }

    map<char, ll> hang[10], cot[10], nhom[10];
    for (ll i=0; i<9; i++)  
        for (ll j=0; j<9; j++)
        {
            ++hang[i][c[i][j]];
            ++cot[j][c[i][j]];
            ++nhom[(i/3)*3+j/3][c[i][j]];
        }

    for (ll i=0; i<9; i++)
    for (char x='0'; x<='9'; x++)
    {
        if (hang[i][x]>1)
        {
            cout<<"GRESKA";
            return;
        }
        if (cot[i][x]>1)
        {
            cout<<"GRESKA";
            return;
        }
        if (nhom[i][x]>1)
        {
            cout<<"GRESKA";
            return;
        }
    }
    cout<<"OK";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}