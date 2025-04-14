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
    string s; cin>>s;
    ll n=s.size();
    s=" "+s;
    char mx='a', mn='z';
    for (ll i=2; i<=n-1; i++) 
    {
        mx=max(mx, s[i]);
        mn=min(mn, s[i]);
    }
    if (mn<=s[1] && mn<=s[n])
    {
        ll pos=2;
        for (ll i=2; i<=n; i++) if (s[i]<s[pos]) pos=i;
        cout<<s.substr(1, pos-1)<<" "<<s[pos]<<" "<<s.substr(pos+1)<<endl;
        return;
    }
    else 
    {
        ll start=2, len=1;
        for (ll i=2; i<=n-1; i++) if (s[i]==mx)
        {
            ll j=i;
            while (j<=n-1 && s[j]==mx) ++j;
            if (j-i>len)
            {
                start=i;
                len=j-i;
            }
            i=j-1;
        }  
        cout<<s.substr(1, start-1)<<" "<<s.substr(start, len)<<" "<<s.substr(start+len)<<endl;
        return;
    }
    cout<<":\n";
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