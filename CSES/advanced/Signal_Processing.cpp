/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define endl '\n'
const ll mod = 1e9+7;
const ll maxn = (1<<19);
const ld PI=acos(-1);
typedef complex<ld> base;
typedef vector<base> vb;
vb a(maxn), b(maxn);
ll k, n, m;

void fft(vb &a, ll n, ll inv)    //n = 2^x
{
    if (n==1) return;
    vb a_even(n/2), a_odd(n/2);
    for (ll i=0, j=0; i<n; i+=2)
    {
        a_even[j]=a[i];
        a_odd[j]=a[i+1];
        ++j;
    }
    fft(a_even, n/2, inv);
    fft(a_odd, n/2, inv);
    ld ang=2*PI/n;
    if (inv==true) ang=-ang;
    base w(1), wn(cos(ang), sin(ang));
    for (ll i=0; i<n/2; i++)
    {
        a[i]=a_even[i]+w*a_odd[i];
        a[i+n/2]=a_even[i]-w*a_odd[i];
        if (inv==true)
        {
            a[i]/=2;
            a[i+n/2]/=2;
        }
        w*=wn;
    }
}

void solve()
{
    ll n, m; cin>>n>>m;  
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        a[i]=x;
    }
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        b[m-1-i]=x;
    }
    fft(a, maxn, false);
    fft(b, maxn, false);
    for (ll i=0; i<maxn; i++) a[i]*=b[i];
    fft(a, maxn, true);
    for (ll i=0; i<n+m-1; i++) cout<<llround(a[i].real())<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}