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
    ll n, m, q; cin>>n>>m>>q;
    ll chuki=__gcd(n, m);
    while (q--)
    {
        ll sx, sy, ex, ey; cin>>sx>>sy>>ex>>ey;
        ll a=n/chuki;
        ll b=m/chuki;
        --sy; --ey;
        ll v1 = sy / (sx == 1 ? a : b);
		ll v2 = ey / (ex == 1 ? a : b);
        if (v1==v2) cout<<"YES\n";
        else cout<<"NO\n"; 
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