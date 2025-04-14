/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    ll x, y; cin>>x>>y;
    ll u=abs(a-c);
    ll v=abs(b-d);
    if (u%x!=0 || v%y!=0) cout<<"NO";
    else
    {
        u/=x;
        v/=y;
        if ((u+v)%2==1) cout<<"NO";
        else cout<<"YES";
    }
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