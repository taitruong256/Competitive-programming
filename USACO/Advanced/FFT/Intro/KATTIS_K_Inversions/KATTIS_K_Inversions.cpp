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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

const ld PI=acos(-1);
typedef complex<ld> base;
typedef vector<base> vb;

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

vector<ll> mul(vector<ll> A, vector<ll> B)
{
    vb a(A.size()), b(B.size());
    for (ll i=0; i<A.size(); i++) a[i]+=A[i];
    for (ll i=0; i<B.size(); i++) b[i]+=B[i];
    ll n=1;
    while (n<a.size()+b.size()) n*=2;
    a.resize(n);
    b.resize(n);
    fft(a, n, false);
    fft(b, n, false);
    for (ll i=0; i<n; i++) a[i]*=b[i];
    fft(a, n, true);
    vector<ll> ans;
    for (auto i: a) ans.push_back(llround(i.real()));
    return ans;
}

void solve()
{
    string s; cin>>s; s=" "+s;
    ll n=s.size()-1;
    vector<ll> a(n+1), b(n+1);
    for (ll i=1; i<=s.size()-1; i++)
    {
        if (s[i]=='A') a[i]=1;
        else b[n-i]=1;
    }
    vector<ll> c=mul(a, b);
    for (ll i=n+1; i<=2*n-1; i++) cout<<c[i]<<endl;
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