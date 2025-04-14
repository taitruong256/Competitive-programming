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

ll n;
string s;

bool check(ll i)
{
    if (s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') return true;
    return false;
}

void solve()
{
    cin>>s; 
    n=s.size(); 
    s=" "+s+"      ";
    ll q; cin>>q;
    set<ll> st;
    for (ll i=1; i<=n; i++) if (check(i)) st.insert(i);
    while (q--)
    {
        ll i;
        char v; 
        cin>>i>>v;
        s[i]=v;
        if (v=='1')
        {
            if (i>=3 && st.find(i-2)!=st.end()) st.erase(i-2);
            if (i>=4 && st.find(i-3)!=st.end()) st.erase(i-3);
            if (i>=2 && check(i-1)) st.insert(i-1);
            if (check(i)) st.insert(i);
        }
        else 
        {
            if (i>=2 && st.find(i-1)!=st.end()) st.erase(i-1);
            if (st.find(i)!=st.end()) st.erase(i);
            if (i>=3 && check(i-2)) st.insert(i-2);
            if (i>=4 && check(i-3)) st.insert(i-3);
        }
        if (st.size()>0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}