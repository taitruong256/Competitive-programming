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
#define endl '\n'
const ll mod = 1e9+7;
bool is_prime[35005];
vector<ll> prime;

bool check_prime(ll n)
{
    if (n<2) return false;
    for (auto i: prime)
    {
        if (i*i>n) break;
        if (n%i==0) return false;
    }
    return true;
}

void solve()
{
    for (ll i=2; i<=35000; i++) is_prime[i]=true;
    for (ll i=2; i<=35000; i++) if (is_prime[i]==true)
        for (ll j=i*i; j<=35000; j+=i) is_prime[j]=false;
    for (ll i=1; i<=35000; i++) if (is_prime[i]==true) prime.push_back(i);
    
    ll n; cin>>n;  
    if (n==4)
    {
        cout<<2<<endl<<2<<" "<<2;
        return;
    }
    if (check_prime(n)==true) 
    {
        cout<<1<<endl<<n;
        return;
    }
    for (auto i: prime)
    {
        if (i>1000) break;
        for (auto j:prime)
        {
            if (j>1000) break;
            if (check_prime(n-i-j)==true)
            {
                cout<<3<<endl<<i<<" "<<j<<" "<<n-i-j;
                return;
            }
        }
    }
    
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