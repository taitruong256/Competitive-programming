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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    char c[4][4];
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) cin>>c[i][j];
    
    set<char> hang[4], cot[4], cheochinh, cheophu;
    for (ll i=1; i<=3; i++)
    {
        for (ll j=1; j<=3; j++)
        {
            hang[i].insert(c[i][j]);
            cot[j].insert(c[i][j]);
            if (i==j) cheochinh.insert(c[i][j]);
            if (i+j==4) cheophu.insert(c[i][j]);
        }
    }
    for (ll i=1; i<=3; i++) if (hang[i].size()==1 && *hang[i].begin()!='.')
    {
        cout<<*hang[i].begin()<<endl;
        return;
    }
    for (ll i=1; i<=3; i++) if (cot[i].size()==1 && *cot[i].begin()!='.')
    {
        cout<<*cot[i].begin()<<endl;
        return;
    }
    if (cheochinh.size()==1 && *cheochinh.begin()!='.')
    {
        cout<<*cheochinh.begin()<<endl;
        return;
    }
    if (cheophu.size()==1 && *cheophu.begin()!='.')
    {
        cout<<*cheophu.begin()<<endl;
        return;
    }
    cout<<"DRAW\n";
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