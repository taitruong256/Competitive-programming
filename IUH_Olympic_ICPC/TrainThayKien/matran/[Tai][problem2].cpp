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
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, k; 
struct matran {ll a[21][21];};
matran I, a, sum, ans;

matran operator * (matran a, matran b)
{
    matran c;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) c.a[i][j]=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            for (ll k=1; k<=n; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mod;  
            }
    return c;
}

matran operator + (matran a, matran b)
{
    matran c;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) c.a[i][j]=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            c.a[i][j]=a.a[i][j]+b.a[i][j];
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

matran B(matran a, ll k)
{
    if (k==0) return I;
    if (k==1) return a;
    if (k%2==0) return (I+luythua(a, k/2))*B(a, k/2);
    return (I+luythua(a, k/2))*B(a, k/2)+luythua(a, k);
}

void solve()
{
    cin>>n>>k;                
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) 
            if (i==j) I.a[i][j]=1;
            else I.a[i][j]=0;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a.a[i][j], sum.a[i][j]=0;
    
    sum=B(a, k);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cout<<sum.a[i][j]<<" \n"[j==n]; cout<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}