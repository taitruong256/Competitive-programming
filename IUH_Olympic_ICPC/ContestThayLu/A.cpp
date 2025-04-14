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
const ll inf = 1e14+5;
bool prime[10000005];
vector<ll> nt;
map<ll, ll> phantich;

ll tinh(ll p, ll n)
{
    ll x1=p;
    ll xn=n/p*p;
    ll u1=n-xn+1;
    ll un=n-x1+1;
    ll sl=(un-u1)/p+1;
    if (2*inf/sl<u1+un) return inf;
    return sl*(u1+un)/2;
}

bool check(ll n)   //kiem tra n! cho chia het
{
    for (auto i: phantich)
    {
        ll res=0, p=i.first;
        bool check=false;
        while (p<=n) 
        {
            res+=tinh(p, n);
            if (res>=i.second) break;
            if (n/i.first<p) break;
            p=p*i.first;
        }
        if (res<i.second) return false;
    }
    return true;
}

void solve()
{
    ll n; cin>>n; 
    //san nguyen to
    for (ll i=1; i<=10000000; i++) prime[i]=true;
    prime[1]=false;
    for (ll i=2; i<=10000000; i++) if (prime[i]==true)
        for (ll j=i*i; j<=10000000; j+=i) prime[j]=false;
    for (ll i=1; i<=10000000; i++) if (prime[i]==true) nt.push_back(i);


    //phan tich thua so trong can(n)
    ll m=n;
    for (auto i: nt)
    {   
        if (i*i>m) break;
        while (m%i==0) ++phantich[i], m/=i;
    }
    if (m>1) ++phantich[m];

    if (n==1)
    {

            cout<<0;
            return;
    }


    //chat nhi phan log(n)*(so thua so p cua n)*log(p)(n)
    ll l=1, r=n, ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
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