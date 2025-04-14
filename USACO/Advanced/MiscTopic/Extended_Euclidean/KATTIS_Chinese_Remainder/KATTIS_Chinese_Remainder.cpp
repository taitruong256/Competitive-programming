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

ll extended_euclidean(ll a, ll b, ll &x, ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1, y1, g=extended_euclidean(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

ll binmul(ll a, ll b, ll mod)
{
    if (b==0)return 0;
    ll tmp=binmul(a, b/2, mod);
    tmp=(tmp+tmp)%mod;
    if (b%2==1) tmp=(tmp+a)%mod;
    return tmp;
}

void solve()
{
    ll a1, m1, a2, m2, n1, n2, x; cin>>a1>>m1>>a2>>m2;
    extended_euclidean(m1, m2, n1, x);
    extended_euclidean(m2, m1, n2, x);
    n1=(n1+m2)%m2;
    n2=(n2+m1)%m1;
    ll a=(binmul(binmul(a1, n2, m1*m2), m2, m1*m2)+binmul(binmul(a2, n1, m1*m2), m1, m1*m2))%(m1*m2);
    cout<<a<<" "<<m1*m2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}