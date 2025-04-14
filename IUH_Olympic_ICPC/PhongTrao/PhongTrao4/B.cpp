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
    if (n==1)
    {
        cout<<0<<" "<<1<<endl;
        return;
    }
    ll t2=(n/7)*2;
    ll tam=n%7;
    if (tam>=6) ++t2;
    ll t7=2;
    n-=2;
    t7+=(n/7)*2;
    tam=n%7;
    if (tam>=6) ++t7;
    cout<<min(t2, t7)<<" "<<max(t2, t7)<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    //ll t; cin>>t; while (t--)
    solve();
    return 0;
}