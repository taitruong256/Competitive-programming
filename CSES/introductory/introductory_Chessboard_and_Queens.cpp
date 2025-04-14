/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
char grid[10][10];
bool cheochinh[20], cheophu[20], cot[20];
ll ans=0;

void dequy(ll hang)
{
    if (hang==8) 
    {
        ++ans;
        return;
    }
    for (ll c=0; c<8; c++) if (cot[c]==false && grid[hang][c]=='.' && cheochinh[hang-c+7]==false && cheophu[hang+c]==false)
    {
        cot[c]=true;
        cheochinh[hang-c+7]=true;
        cheophu[hang+c]=true;
        dequy(hang+1);
        cot[c]=false;
        cheochinh[hang-c+7]=false;
        cheophu[hang+c]=false;
    }
}

void solve()
{
    memset(cheochinh, false, sizeof(cheochinh));
    memset(cheophu, false, sizeof(cheophu));
    memset(cot, false, sizeof(cot));
    for (ll i=0; i<8; i++)
        for (ll j=0; j<8; j++) cin>>grid[i][j];
    dequy(0);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}