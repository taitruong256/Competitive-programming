/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e9;
ll n, k; 
struct matran {ll a[21][21];};
matran I, T, coso;

matran operator * (matran a, matran b)
{
    matran c;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++) c.a[i][j]=0;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++)
            for (ll k=1; k<=2; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=100;
            }
    return c;
}

matran luythua(matran a, ll n)
{
    matran ans=I;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++) if (i==j) I.a[i][j]=1; else I.a[i][j]=0;
    while (n>0)
    {
        if (n&1) ans=ans*a;
        a=a*a;
        n/=2;
    }
    return ans;
}

void solve()
{
    cin>>n;          
    matran X=luythua(coso, n);
    ll ans=(X.a[1][1]*2-1+100)%100;
    if (ans<10) cout<<"0"<<ans<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    coso.a[1][1]=2; coso.a[1][2]=3;
    coso.a[2][1]=1; coso.a[2][2]=2;
    I.a[1][1]=1; I.a[1][2]=0;
    I.a[2][1]=0; I.a[2][2]=1;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}

