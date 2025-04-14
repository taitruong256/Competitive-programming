/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a=0, b=0;
    deque<ll> dq;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        dq.push_back(x);
    }
    ll luot=0;
    while (!dq.empty())
    {
        if (luot==0)
        {
            if (dq.front()>dq.back())
            {
                a+=dq.front();
                dq.pop_front();
            }
            else 
            {
                a+=dq.back();
                dq.pop_back();
            }
        }
        else
        {
            if (dq.front()>dq.back())
            {
                b+=dq.front();
                dq.pop_front();
            }
            else 
            {
                b+=dq.back();
                dq.pop_back();
            }
        }
        luot^=1;
    }
    cout<<a<<" "<<b;
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