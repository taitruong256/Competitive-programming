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
typedef long long ll;

void solve()
{
    ll a, b; cin>>a>>b;
    vector<ll> divisor;
    for (ll i=1; i*i<=a; i++) if (a%i==0)
    {
        divisor.push_back(i);
        if (i*i!=a) divisor.push_back(a/i);
    }
    sort(divisor.begin(), divisor.end());
    if (b>divisor.size()) cout<<-1;
    else cout<<divisor[b-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}