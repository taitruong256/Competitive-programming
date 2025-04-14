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

ll n, k, a[100005];

bool check(ld m)
{
    ll s=0;
    for (ll i=1; i<=n; i++) s+=(ll)(sqrt(1+4*a[i]/m)-1)/2;
    return s>=k;
}

void solve()
{
    cin>>n>>k;
    k-=n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ld l=0, r=1e18;
    for (ll i=0; i<300; i++)
    {
        ld mid=(l+r)/2;
        if (check(mid)==true) l=mid;
        else r=mid;
    }
    ld ans=0;
    ll cnt=0;
    for (ll i=1; i<=n; i++)
    {
        ll x=(sqrt(1+4*a[i]/l)-1)/2;
        ans+=1.0*a[i]/(x+1);
        cnt+=x;
    }
    cout<<llround(ans-l*(k-cnt));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    freopen("tallbarn.in", "r", stdin);
    freopen("tallbarn.out", "w", stdout);
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}