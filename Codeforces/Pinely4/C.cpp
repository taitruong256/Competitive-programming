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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, a[200005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (n==1)
    {
        cout<<1<<endl;
        cout<<a[1]<<endl;
        return;
    }
    ll mx=*max_element(a+1, a+n+1), mn=*min_element(a+1, a+n+1);
    vector<ll> ans;
    ll maxiter=40;
    while (maxiter--)
    {
        ll new_mx=0, new_mn=1e18, mid=(mx+mn)/2;
        if (mid==0) break;
        if ((mx+mn)%2==1) 
        {
            cout<<-1<<endl;
            return;
        }
        ans.push_back(mid);
        for (ll i=1; i<=n; i++) a[i]=abs(a[i]-mid), new_mx=max(new_mx, a[i]), new_mn=min(new_mn, a[i]);
        mx=new_mx;
        mn=new_mn;
    }
    if (mx>0 || mn>0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}