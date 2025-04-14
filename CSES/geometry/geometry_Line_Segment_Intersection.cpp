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

ll locate(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a=y1-y2, b=x2-x1;
    ll c=-a*x2-b*y2;
    return a*x3+b*y3+c;
}

bool on_segment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    if (x3>=min(x1, x2) && x3<=max(x1, x2) && y3>=min(y1, y2) && y3<=max(y1, y2)) return true;
    else return false;
}

void solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4; cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    ll t=locate(x1, y1, x2, y2, x3, y3);   
    for (ll i=0; i<2; i++)
    {
        ll x=locate(x1, y1, x2, y2, x3, y3);
        ll y=locate(x1, y1, x2, y2, x4, y4);
        if (x==0 && y==0)
        {
            if (on_segment(x1, y1, x2, y2, x3, y3)==false && on_segment(x1, y1, x2, y2, x4, y4)==false)
            {
                swap(x1, x3);
                swap(y1, y3);
                swap(x2, x4);
                swap(y2, y4);
                if (on_segment(x1, y1, x2, y2, x3, y3)==true && on_segment(x1, y1, x2, y2, x4, y4)==true)
                {
                    cout<<"YES\n";
                    return;
                }
                else
                {
                    cout<<"NO\n";
                    return;
                }
            }   
            else 
            {
                cout<<"YES\n";
                return;
            }
        }
        if ((x<0 && y<0) || (x>0 && y>0))
        {
            cout<<"NO\n";
            return;
        }
        swap(x1, x3);
        swap(y1, y3);
        swap(x2, x4);
        swap(y2, y4);
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}