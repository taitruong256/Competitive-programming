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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n, k, x; cin>>n>>k>>x;
    set<ll> st;
    for (ll i=1; i<=k; i++) st.insert(i);
    st.erase(x);
    vector<ll> ans;
    if (x!=1)
    {
        cout<<"YES\n";
        cout<<n<<endl;
        for (ll i=1; i<=n; i++) cout<<1<<" "; cout<<endl;
        return;
    }
    else
    {
        set<ll> st;
        for (ll i=1; i<=k; i++) st.insert(i);
        st.erase(x);
        vector<ll> ans;
        if (st.size()==0)
        {
            cout<<"NO\n";
            return;
        } 

        while (n>0)
        {
            if (st.find(n)!=st.end())
            {
                ans.push_back(n);
                n-=n;
                break;
            }
            if (n>0) 
            {
                ans.push_back(*st.begin());
                n-=*st.begin();
            }
        }
        if (n<0 || ans.size()==0)
        {
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" "; cout<<endl;
    }
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