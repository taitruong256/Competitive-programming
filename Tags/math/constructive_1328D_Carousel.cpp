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
    ll n; cin>>n;
    ll a[n+5];
    set<ll> st;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    if (st.size()==1)
    {
        cout<<1<<endl;
        for (ll i=1; i<=n; i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    else if (n%2==0)
    {
        cout<<2<<endl;
        for (ll i=1; i<=n; i++) cout<<i%2+1<<" ";
        cout<<endl;
        return;
    }
    else 
    {
        ll pos=-1;
        for (ll i=1; i<=n; i++)
        {
            if (i<n && a[i]==a[i+1])
            {
                pos=i;
                break;
            } 
            else if (i==n && a[n]==a[1])
            {
                pos=i;
                break;
            }
        }
        if (pos!=-1)
        {
            cout<<2<<endl;
            for (ll i=1; i<=pos; i++) cout<<i%2+1<<" ";
            for (ll i=pos+1; i<=n; i++) cout<<(i+1)%2+1<<" ";
            cout<<endl;
            return;
        }
        else 
        {
            cout<<3<<endl;
            for (ll i=1; i<=n/2; i++) cout<<1<<" "<<2<<" ";
            cout<<3<<endl;
            return;
        }
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