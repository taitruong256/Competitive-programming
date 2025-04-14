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

void solve()
{
    ll a, b, c; cin>>a>>b>>c;
    ll khoangcach=abs(a-b);
    if (a>khoangcach*2 || b>khoangcach*2 || c>khoangcach*2)
    {
        cout<<-1<<endl;
        return;
    }
    --a, --b, --c;
    c+=khoangcach;
    c%=(khoangcach*2);
    cout<<c+1<<endl;

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