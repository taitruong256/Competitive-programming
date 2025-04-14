/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort


         __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  

=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
struct point{ll x, y;};
point p[100005];
ll n;

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    ll area=0;
    for (ll i=0; i<n; i++) area+=(p[i].x*p[(i+1)%n].y)-(p[(i+1)%n].x*p[i].y);
    area=abs(area);
    ll bound=0;
    for (ll i=0; i<n; i++) bound+=__gcd(abs(p[i].x-p[(i+1)%n].x), abs(p[i].y-p[(i+1)%n].y));
    ll inside=(area-bound+2)/2;
    cout<<inside<<" "<<bound;
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