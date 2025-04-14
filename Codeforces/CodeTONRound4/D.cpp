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

void solve()
{
    ll q; cin>>q;
    ll h_low=0, h_high=1e18;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll a, b, n; cin>>a>>b>>n;
            assert(a>b);
            ll low, high;
            if (n==1)
            {
                low=1;
                high=a;
            }
            else 
            {
                low=(a-b)*(n-1)+b+1;
                high=(a-b)*(n-1)+a;
            }
            if (low>h_high || high<h_low)
            {
                cout<<0<<" ";
            }
            else 
            {
                cout<<1<<" ";
                h_low=max(h_low, low);
                h_high=min(h_high, high);
            }
        }
        else 
        {
            ll a, b; cin>>a>>b;
            assert(a>b);
            if (a>=h_high)
            {
                cout<<1<<" ";
                continue;
            }
            ll sobuoc_low=(h_low-a+a-b-1)/(a-b)+1;
            ll sobuoc_high=(h_high-a+a-b-1)/(a-b)+1;
            if (sobuoc_low==sobuoc_high) cout<<sobuoc_high<<" ";
            else cout<<-1<<" ";
        }
    }
    cout<<endl;
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