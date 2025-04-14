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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18+5;
const ll maxn = 1e7;
vector<int> nt;
int minprime[maxn+5], a[10000005];
ll somu[maxn+5];
 
ll tinh(ll n, ll p)
{
    ll cnt=0, pw=1;
    while (n/p>=pw)
    {
        pw=pw*p;
        cnt+=n/pw;
    }
    return cnt;
}
 
bool check(ll n)
{
    for (auto i: nt) if (tinh(n, i)<somu[i]) return false;
    return true;
}

ll bs()
{
    ll l=0, r=1e13+7;
    while (true)
    {
        if (l==r) return l;
        if (r-l==1) check(l)==true?l:r;
        long long mid=(l+r)/2; 
        if (check(mid)==true) r=mid;
        else l=mid+1;
    }
    return l;
}
 
void solve()
{
    memset(minprime, 0, sizeof(minprime));
    minprime[1]=1;
    for (ll i=2; i*i<=maxn; i++) if (minprime[i]==0)
        for (ll j=i*i; j<=maxn; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=1; i<=maxn; i++) if (minprime[i]==0) minprime[i]=i;
    for (ll i=2; i<=maxn; i++) if (minprime[i]==i) nt.push_back(i);
 
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for (ll i=0; i<n; i++)
        for (ll j=a[i]+1; j<=a[i+1]; j++)
        {
            ll x=j;
            while (x>1)
            {
                somu[minprime[x]]+=n-i;
                x/=minprime[x];
            }
        }
    cout<<bs();
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    freopen("factorial.inp", "r", stdin);
    freopen("factorial.out", "w", stdout);
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}