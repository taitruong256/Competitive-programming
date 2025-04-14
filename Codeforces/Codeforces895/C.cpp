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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll minprime[10000005];
vector<ll> nt;

void solve()
{
    ll l, r; cin>>l>>r; 
    if (minprime[r]!=r)
    {
        ll x=r/minprime[r];
        cout<<x<<" "<<r-x<<endl;
        return;
    }
    ll x=upper_bound(nt.begin(), nt.end(), r)-nt.begin()-1;
    if (x==-1) 
    {
        cout<<-1<<endl;
        return;
    }
    x=nt[x];                    
    ll a=x-1, b=x+1;
    if (l<=a && a<=r && a>=4) 
    {
        cout<<2<<" "<<a-2<<endl;
        return;
    }
    if (l<=b && b<=r && b>=4)
    {
        cout<<2<<" "<<b-2<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    minprime[1]=1;
    for (ll i=2; i*i<=10000000; i++) if (minprime[i]==0)
        for (ll j=i*i; j<=10000000; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=2; i<=10000000; i++) 
        if (minprime[i]==0) minprime[i]=i, nt.push_back(i);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}