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
point p[200005];
ll n;
vector<point> hull;

ll located(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a=y1-y2, b=x2-x1;
    ll c=-a*x2-b*y2;
    ll t=a*x3+b*y3+c;
    if (t==0) return 0;
    else if (t<0) return -1;
    else return 1;
}

bool comp(point a, point b)
{
    return make_pair(a.x, a.y)<make_pair(b.x, b.y);
}

void convex_hull()
{
    ll t=2;
    while (t--)
    {
        for (ll i=0; i<n; i++)
        {
            while (hull.size()>=2)
            {
                point b=hull[hull.size()-2];
                point a=hull[hull.size()-1];
                point c=p[i];
                if (located(a.x, a.y, b.x, b.y, c.x, c.y)<0) hull.pop_back();
                else break;
            }
            hull.push_back(p[i]);
        }
        hull.pop_back();
        reverse(p, p+n);
    }
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    sort(p, p+n, comp); 
    convex_hull();
    cout<<hull.size()<<endl;
    for (ll i=0; i<hull.size(); i++) cout<<hull[i].x<<" "<<hull[i].y<<endl;
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