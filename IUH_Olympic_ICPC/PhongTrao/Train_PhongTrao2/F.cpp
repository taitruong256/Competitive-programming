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
    ll n, a, b; cin>>n>>a>>b;  
    if (a<=n/2 && b>n/2)
    {
        cout<<"Final!";
        return;
    }
    ll ans=0;
    while (a!=b)
    {
        a=(a+1)/2;
        b=(b+1)/2;
        ++ans;
    }
    if (ans==(ll)log2(n)) 
    {
        {
        cout<<"Final!";
        return;
    }
    }
    cout<<ans;
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