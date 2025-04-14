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
const ll mod = 1e9+7;
const ll inf = 1e9;
ll a[6][6], b[6][6];

void xoay()
{
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) b[i][j]=a[]
}

void solve()
{
    // for (ll i=0; i<16; i++)
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) a[i][j]=(i-1)*3+j;
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