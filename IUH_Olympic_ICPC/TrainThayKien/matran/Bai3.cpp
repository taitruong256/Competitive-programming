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
const ll mod = 1e15+7;
const ll inf = 1e9;
ll n, k; 
struct matran {ll a[21][21];};
matran I, T, coso;

ll modulo(ll a, ll b)
{
    if (b==0) return 0;
    if (b==1) return 1;
    ll tam=modulo(a, b/2);
    if (b%2==0) return (tam+tam)%mod;
    return (tam+tam+a)%mod;
}

matran operator * (matran a, matran b)
{
    matran c;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) c.a[i][j]=0;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++)
            for (ll k=1; k<=3; k++)
            {
                c.a[i][j]+=modulo(a.a[i][k], b.a[k][j]);
                c.a[i][j]%=mod;  
            }
    return c;
}

matran operator + (matran a, matran b)
{
    matran c;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) c.a[i][j]=0;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++)
        {
            c.a[i][j]=modulo(a.a[i][j], b.a[i][j]);
            c.a[i][j]%=mod;  
        } 
    return c;
}

matran luythua(matran a, ll n)
{
    matran ans=I;
    while (n>0)
    {
        if (n&1) ans=ans*a;
        a=a*a;
        n/=2;
    }
    return ans;
}

matran tinh(ll n)
{
    matran ans=luythua(coso, n-3);
    ans=ans*T;
    return ans;
}

matran B(matran a, ll k)
{
    if (k==0) return I;
    if (k==1) return a;
    if (k%2==0) return (I+luythua(a, k/2))*B(a, k/2);
    return (I+luythua(a, k/2))*B(a, k/2)+luythua(a, k);
}

void solve()
{
    cin>>n;
    matran X=tinh(n);
    cout<<X.a[3][1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    coso.a[1][1]=1; coso.a[1][2]=1; coso.a[1][3]=1;
    coso.a[2][1]=1; coso.a[2][2]=0; coso.a[2][3]=0; 
    coso.a[3][1]=0; coso.a[3][2]=1; coso.a[3][3]=0;
    T.a[1][1]=11; T.a[2][1]=6; T.a[3][1]=3;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=3; j++) if (i==j) I.a[i][j]=1; else I.a[i][j]=0;

    solve();
    return 0;
}

