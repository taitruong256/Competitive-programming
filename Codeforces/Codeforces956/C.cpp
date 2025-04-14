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

ll n, a[5][200005];

void display(ll index, vector<ll> v)
{
    if (index==1) cout<<v[0]<<" "<<v[1]<<" ";
    else if (index==2) cout<<v[2]<<" "<<v[3]<<" ";
    else cout<<v[4]<<" "<<v[5]<<" ";
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=3; i++)
        for (ll j=1; j<=n; j++)
            cin>>a[i][j];
    
    vector<ll> v={1, 2, 3}, ans, ord;
    ll tot=0, check=0;
    for (ll i=1; i<=n; i++) tot+=a[1][i]; 
    tot=(tot+2)/3;  
    do 
    {
        ll x=v[0], y=v[1], z=v[2];

        ll la=1, ra=1, suma=a[x][1];
        for (ll i=2; i<=n; i++)
            if (suma<tot) suma+=a[x][i], ra=i;
            else break;
        
        ll lc=n, rc=n, sumc=a[z][n];
        for (ll i=n-1; i>=ra+1; i--)
            if (sumc<tot) sumc+=a[z][i], lc=i;
            else break;

        ll lb=ra+1, rb=lc-1, sumb=0;
        for (ll i=ra+1; i<=lc-1; i++) sumb+=a[y][i];

        if (suma>=tot && sumb>=tot && sumc>=tot)
        {
            check=1;
            ans={la, ra, lb, rb, lc, rc};
            ord=v;
        }

        // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"        "<<suma<<" "<<sumb<<" "<<sumc<<"         ";
        // for (auto i: {la, ra, lb, rb, lc, rc}) cout<<i<<" "; cout<<endl;
    }
    while (next_permutation(v.begin(), v.end()));
    if (check==0) cout<<-1<<endl;
    else 
    {
        // for (auto i: ans) cout<<i<<" "; cout<<endl;
        // for (auto i: ord) cout<<i<<" "; cout<<endl;
        for (ll i=0; i<3; i++) if (ord[i]==1) cout<<ans[i*2]<<" "<<ans[i*2+1]<<" ";
        for (ll i=0; i<3; i++) if (ord[i]==2) cout<<ans[i*2]<<" "<<ans[i*2+1]<<" ";
        for (ll i=0; i<3; i++) if (ord[i]==3) cout<<ans[i*2]<<" "<<ans[i*2+1]<<" ";
        cout<<endl;
    }
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