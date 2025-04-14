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
    ll n, k; cin>>n>>k;
    string s, t; cin>>s>>t;
    string x=s, y=t;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (n>=2*k)
    {
        if (x==y)
        {
            cout<<"YES\n";
            return;
        }
        else 
        {
            cout<<"NO\n";
            return;
        }
    }
    
    set<string> st;
    s=" "+s;
    queue<string> q;
    q.push(s);
    st.insert(s);
    while (!q.empty())
    {
        string s=q.front(); q.pop();  
        for (ll i=1; i<=n; i++) 
        {
            if (i+k<=n) 
            {
                swap(s[i], s[i+k]);
                if (st.find(s)==st.end()) 
                {
                    st.insert(s);
                    q.push(s);
                }
                swap(s[i], s[i+k]);
            }
            if (i+k+1<=n)
            {
                swap(s[i], s[i+k+1]);
                if (st.find(s)==st.end()) 
                {
                    st.insert(s);
                    q.push(s);
                }
                swap(s[i], s[i+k+1]);
            }
        }
    }
    t=" "+t;
    if (st.find(t)!=st.end()) cout<<"YES\n";
    else cout<<"NO\n";
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