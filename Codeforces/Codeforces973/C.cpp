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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;
 
ll query(string s)
{
    cout<<"? "<<s<<endl;
    ll x; cin>>x;
    return x;
}
 
void solve()
{
    ll n; cin>>n;
    string ans="0";
    if (query("0")==0) 
    {
        cout<<"! "; for (ll i=0; i<n; i++) cout<<1;
        cout<<endl;
        return;
    }
    ll cnt=0;
    while (ans.size()<n)
    {
        ll x=query(ans+"0"); cnt+=1;
        if (x==1) ans=ans+"0";
        else
        {
            ll y=query(ans+"1"); cnt+=1;
            if (y==1) ans=ans+"1";
            else break;
        }
    }
    while (ans.size()<n-1)
    {
        ll x=query("0"+ans); cnt+=1;
        if (x==1) ans="0"+ans;
        else
        {
            ll y=query("1"+ans); cnt+=1;
            if (y==1) ans="1"+ans; 
            else break; 
        }
    }
    if (ans.size()==n) cout<<"! "<<ans<<endl;    
    else 
    {
        assert(cnt<=2*n-1);
        ll x=query("0"+ans);
        if (x==1) cout<<"! 0"<<ans<<endl;
        else cout<<"! 1"<<ans<<endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}