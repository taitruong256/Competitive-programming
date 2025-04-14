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
    ll n, x; cin>>n>>x;
    if (x>n)
    {
        cout<<-1<<endl;
        return;
    }
    if (x==n)
    {
        cout<<n<<endl;
        return;
    }
    for (ll i=0; i<=63; i++) if (!(n&(1LL<<i)) && (x&(1LL<<i)))
    {
        cout<<-1<<endl;
        return;
    }

    vector<ll> bitn, bitx;
    for (ll i=0; i<=63; i++) if (n&(1LL<<i)) bitn.push_back(i);
    for (ll i=0; i<=63; i++) if (x&(1LL<<i)) bitx.push_back(i);
    reverse(bitn.begin(), bitn.end());
    reverse(bitx.begin(), bitx.end());
    for (auto i: bitn) cout<<i<<" "; cout<<endl;
    for (auto i: bitx) cout<<i<<" "; cout<<endl;

    if (x==0)
    {
        ll t=bitn.front()+1;
        cout<<(1LL<<t)<<endl;
        return;
    }
    

    ll pos=0;
    for (ll i=0; i<bitn.size(); i++) if (bitn[i]!=bitx[i]) 
    {
        pos=i;
        break;
    } 

    if (pos==0)
    {
        cout<<-1<<endl;
        return;
    }

    if (bitn[pos]==bitn[pos-1]-1)
    {
        cout<<-1<<endl;
        return;
    }

    ll ans=0;
    for (ll i=pos; i<bitn.size(); i++) ans+=(1LL<<bitn[i]); 
    ans=(1LL<<(bitn[pos]+1))-ans;    
    cout<<n+ans<<endl;
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