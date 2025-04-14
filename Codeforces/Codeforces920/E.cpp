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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n, m; cin>>n>>m;
    ll xa, ya, xb, yb; cin>>xa>>ya>>xb>>yb;
    set<ll> sta[n+1], stb[n+1];
    sta[xa].insert(ya);
    stb[xb].insert(yb);
    ll turn=0, cura=xa, curb=xb;
    while (1==1)
    {
        if (turn==0)
        {
            if (sta[cura].empty())
            {
                cout<<"Bob\n";
                return;
            }
            if (cura==n)
            {
                cout<<"Draw\n";
                return;
            }
            for (auto i: sta[cura]) 
            {
                if (i-1>=1) 
                {
                    sta[cura+1].insert(i-1);
                    if (stb[cura+1].find(i-1)!=stb[cura+1].end()) stb[cura+1].erase(i-1);
                }
                sta[cura+1].insert(i);
                if (stb[cura+1].find(i)!=stb[cura+1].end()) stb[cura+1].erase(i);
                if (i+1<=m) 
                {
                    sta[cura+1].insert(i+1);
                    if (stb[cura+1].find(i+1)!=stb[cura+1].end()) stb[cura+1].erase(i+1);
                }
            }
            cura+=1;
        }
        else 
        {
            if (stb[curb].empty())
            {
                cout<<"Alice\n";
                return;
            }
            if (curb==1)
            {
                cout<<"Draw\n";
                return;
            }
            for (auto i: stb[curb]) 
            {
                if (i-1>=1) 
                {
                    stb[curb-1].insert(i-1);
                    if (sta[curb-1].find(i-1)!=sta[curb-1].end()) sta[curb-1].erase(i-1);
                }
                stb[curb-1].insert(i);
                if (sta[curb-1].find(i)!=sta[curb-1].end()) sta[curb-1].erase(i);
                if (i+1<=m) 
                {
                    stb[curb-1].insert(i+1);
                    if (sta[curb-1].find(i+1)!=sta[curb-1].end()) sta[curb-1].erase(i+1);
                }
            }
            curb-=1;
        }
        turn=1-turn;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}