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
const ll maxn = 200005;
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    if (n%2==1)
    {
        cout<<-1<<endl;
        return;
    }
    deque<ll> mo, dong;
    vector<ll> ans(n+5);
    ll cnt=0;
    for (ll i=0; i<n; i++)
    {
        if (s[i]=='(') mo.push_back(i);
        else 
        {
            dong.push_back(i);
            if (mo.size()>=1 && dong.size()>=1)
            {
                cnt=1;
                ll x=mo.back(); mo.pop_back();
                ll y=dong.back(); dong.pop_back();
                ans[x]=cnt;
                ans[y]=cnt;
            }
        }
    }
    if (dong.size()==0 && mo.size()==0)
    {
        cout<<1<<endl;
        for (ll i=0; i<n; i++) cout<<1<<" "; cout<<endl;
        return;
    }
    else if (dong.size()==mo.size())
    {
        // cout<<mo.size()<<endl;
        // for (auto i: mo) cout<<i<<" "; cout<<endl;
        // cout<<dong.size()<<endl;
        // for (auto i: dong) cout<<i<<" "; cout<<endl;
        bool check=true;
        for (ll i=0; i<mo.size(); i++) if (dong[i]!=i || mo[i]!=n-1-i) check=false;
        if (check==true)
        {
            cout<<1<<endl;
            for (ll i=0; i<n; i++) cout<<1<<" "; cout<<endl;
            return;
        }
        check=true;
        for (ll i=0; i<mo.size()*2; i++) if (dong[i]!=i || mo[i]!=++i) check=false;
        if (check==true)
        {
            cout<<1<<endl;
            for (ll i=0; i<n; i++) cout<<1<<" "; cout<<endl;
            return;
        }
        for (auto i: mo) ans[i]=cnt+1;
        for (auto i: dong) ans[i]=cnt+1;
        cout<<cnt+1<<endl;
        for (ll i=0; i<n; i++) cout<<ans[i]<<" "; cout<<endl;
        return;
    }
    else cout<<-1<<endl;
    
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