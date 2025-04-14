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

ll f_xor(ll r)
{
    if (r%4==0) return r;
    if (r%4==1) return 1;
    if (r%4==2) return r+1;
    return 0;
}

ll f_k(ll r, ll i, ll k)
{
    if (r-k<0) return 0;
    return (r-k)/(1LL<<i)+1;
}

void solve()
{
    ll l, r, i, k; cin>>l>>r>>i>>k;
    ll xor1=(f_xor(r)^f_xor(l-1));
    ll cnt=f_k(r, i, k)-f_k(l-1, i, k);
    // cout<<"---fxor_r  fxor_l: "<<f_k(r, i, k)<<" "<<f_k(l-1, i, k)<<" "<<f_xor(f_k(r, i, k)-1)<<" "<<f_xor(f_k(l-1, i, k)-1)<<endl;
    ll xor2=(f_xor(f_k(r, i, k)-1)^f_xor(f_k(l-1, i, k)-1))*(1LL<<i)+k*(cnt%2);
    // cout<<"---"<<xor1<<"   "<<xor2<<endl;


    // ll xr1=0;
    // for (ll x=l; x<=r; x++) xr1^=x; 
    // ll xr2=0, cnt2=0;
    // for (ll x=l; x<=r; x++) if (x%(1LL<<i)==k) xr2^=x, ++cnt2;
    // ll xr3=0;
    // for (ll x=l; x<=r; x++) if (x%(1LL<<i)!=k) xr3^=x; 
    // cout<<"---"<<xr1<<"   "<<xr2<<" "<<(xr1^xr2)<<" "<<xr3<<endl<<endl;


    cout<<(xor1^xor2)<<endl;
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
