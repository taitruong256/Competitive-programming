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
pair<ll, ll> a[5005];
vector<ll> toado;

ll dientich(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(b.first-a.first)*abs(b.second-a.second);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i].first>>a[i].second;
        toado.push_back(a[i].first*1000000+a[i].second);
    }
    toado.push_back(1e18);
    sort(toado.begin(), toado.end());
    sort(a+1, a+n+1);
    ll cach=0, smax=0, cachmax=1, smin=LLONG_MAX, cachmin=0;
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j++)
            if (a[i].first<a[j].first && a[i].second<a[j].second)
            {
                // cout<<i<<" "<<j<<" "<<dientich(a[i], a[j])<<endl;
                ll x=*lower_bound(toado.begin(), toado.end(), a[i].first*1000000+a[j].second);
                ll y=*lower_bound(toado.begin(), toado.end(), a[j].first*1000000+a[i].second);
                if (x==a[i].first*1000000+a[j].second && y==a[j].first*1000000+a[i].second) 
                {
                    ++cach;
                    if (dientich(a[i], a[j])>smax) smax=dientich(a[i], a[j]), cachmax=1;
                    else if (dientich(a[i], a[j])==smax) smax=dientich(a[i], a[j]), cachmax+=1;
                    if (dientich(a[i], a[j])<smin) smin=dientich(a[i], a[j]), cachmin=1;
                    else if (dientich(a[i], a[j])==smin) smin=dientich(a[i], a[j]), cachmin+=1;
                }
            }
    cout<<cach<<endl;
    cout<<smax<<" "<<cachmax<<endl;
    cout<<smin<<" "<<cachmin<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    solve();
    return 0;
}