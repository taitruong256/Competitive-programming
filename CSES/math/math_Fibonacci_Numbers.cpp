/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
         __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
struct matrix{ll i11, i12, i21, i22;};

matrix multi(matrix a, matrix b)
{
    matrix c;
    c.i11=(a.i11*b.i11+a.i12*b.i21)%mod;
    c.i12=(a.i11*b.i12+a.i12*b.i22)%mod;
    c.i21=(a.i21*b.i11+a.i22*b.i21)%mod;
    c.i22=(a.i21*b.i12+a.i22*b.i22)%mod;
    return c;
}

matrix binpow(matrix a, ll n)
{
    if (n==1) return a;
    matrix temp=binpow(a, n/2);
    if (n%2==0) return multi(temp, temp);
    else return multi(multi(temp, temp), a);
}

void solve()
{
    ll n; cin>>n;
    if (n==0)
    {
        cout<<0;
        return;
    }
    matrix a={1, 1, 1, 0};
    matrix f=binpow(a, n);
    cout<<f.i12;
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