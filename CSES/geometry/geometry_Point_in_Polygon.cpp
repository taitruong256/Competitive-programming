/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
     __                          __
    |  |                        |  |         
 ___|  |__                   ___|  |__  
|__ |   __|                 |__ |   __| 
    |  |    ____    _           |  |    ____  __  __  ____    _____    _____
    |  |   /  _  \ | |          |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
    |  |_  | |_| | | |          |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
    \____\ \____/| |_|          \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                         |  |
                                                                       __/  |
                                                                      |_____/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
struct point{ll x, y;};
ll n, q; 
vector<point> p;

bool on_segment(point a, point b, point c)
{
    if (c.x>=min(a.x, b.x) && c.x<=max(a.x, b.x) && c.y>=min(a.y, b.y) && c.y<=max(a.y, b.y)) return true;
    return false;
}
 
ll locate(point a, point b, point c)
{
    ll i=a.y-b.y;
    ll j=b.x-a.x;
    ll k=-i*b.x-j*b.y;
    ll t=i*c.x+j*c.y+k;
    if (t==0) return 0;
    else if (t<0) return -1;
    else return 1;
}

bool Intersect(point a, point b, point c, point d)
{
    for (ll i=0; i<2; i++)
    {
        ll x=locate(a, b, c);
        ll y=locate(a, b, d);
        if (x==0 && y==0)
        {
            if (on_segment(a, b, c)==false && on_segment(a, b, d)==false)
            {
                swap(a, c);
                swap(b, d);
                if (on_segment(a, b, c)==true && on_segment(a, b, d)==true) return true;
                else return false;
            }   
            else return true;
        }
        if ((x<0 && y<0) || (x>0 && y>0)) return false;
        swap(a, c);
        swap(b, d);
    }
    return true;
}

ll isInside(point pt)
{
    point extreme={inf, pt.x};
    ll cnt=0;
    for (ll i=0; i<n; i++)
    {
        ll j=(i+1)%n;
        if (Intersect(p[i], p[j], pt, extreme)==true)
        {
            if (locate(p[i], p[j], pt)==0) return 1;
            ++cnt;
        }
    }
    if (cnt%2==1) return 2;
    else return 3;
}

void solve()
{
    cin>>n>>q;
    p.resize(0); p.resize(n+5);
    for (ll i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    while (q--)
    {
        point pt; cin>>pt.x>>pt.y;
        ll t=isInside(pt);
        if (t==1) cout<<"BOUNDARY\n";
        else if (t==2) cout<<"INSIDE\n";
        else cout<<"OUTSIDE\n";
    }
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