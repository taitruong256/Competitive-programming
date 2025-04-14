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
    vector<ll> v;
    ll sum=0;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        sum+=x;
        v.push_back(x);
    }

    while (true)
    {
        char c; cin>>c; 
        if (c=='i')
        {
            ll x; cin>>x;
            v.push_back(x);
            sum+=x;
        }
        else if (c=='s')
        {
            cout<<sum<<endl;
        }
        else if (c=='d')
        {
            ll pos; cin>>pos;
            if (pos>=1 && pos<=v.size()) 
            {
                sum-=v[pos-1];
                v.erase(v.begin()+pos-1);
            }
        }
        else if (c=='0') break; 
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