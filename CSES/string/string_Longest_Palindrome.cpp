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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
#define sz(x) (int)(x.size())
const ll mod = 1e9+7;
const ll inf = 1e9;
ll p[3000005];

void solve()
{
    string s; cin>>s;

    //manacher's algorithm
    string t="$";
    for (auto c: s) t+='#', t+=c;
    t=t+"#^";                   
    ll n=t.size();      
    
    memset(p, 0, sizeof(p));
    
    ll c=0, r=0;
    for (ll i=1; i<sz(t)-1; i++)
    {
        ll mirr=2*c-i;
        if (i<r) p[i]=min(p[mirr], r-i);
        while (t[i+(p[i]+1)]==t[i-(p[i]+1)]) ++p[i];
        if (i+p[i]>r) c=i, r=i+p[i];
    }

    ll mx=0, start=0;
    for (ll i=1; i<sz(t); i++) if (p[i]>mx)
    {
        mx=p[i];
        if (i%2==1) start=i/2-1-p[i]/2+1;
        else start=i/2-1-p[i]/2;
    }
    cout<<s.substr(start, mx);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}