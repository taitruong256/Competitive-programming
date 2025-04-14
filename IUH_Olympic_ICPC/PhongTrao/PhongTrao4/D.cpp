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
    for (ll k=1; k<=n; k++)
    {
        ll now=1; 
        cout<<"k = "<<k<<endl;
        cout<<1<<endl;
        for (ll i=1; i<=100; i++)
        {
            now+=k;
            //now%=n;
            //cout<<now<<endl;
            if (now%n==1) 
            {
                cout<<now<<endl;
                break;
            }
        }
        //cout<<endl<<endl;
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