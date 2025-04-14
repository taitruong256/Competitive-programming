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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9, maxn=1e5+5, maxx=1e6+5;
ll minprime[1000005], n, cnt[1000005];
 
void sieve()
{
    minprime[1]=1;
    for (ll i=0; i<maxx; i++) minprime[i]=0;
    for (ll i=0; i<maxx; i++) cnt[i]=0;
    for (ll i=2; i<maxx; i++) if (minprime[i]==0)
        for (ll j=i; j<maxx; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=0; i<maxx; i++) if (minprime[i]==0) minprime[i]=i;
}
 
void solve()
{
    cin>>n;
 
    sieve();
    ll ans=0, sz=0;
    for (ll i=0; i<n; i++)
    {
        ll type, val; cin>>type>>val;
        ll x=val;            
        vector<ll> divisor;
        while(x>1)
        {
            ll y=minprime[x];
            divisor.push_back(y);
            while (x%y==0) x/=y;
        }

        if (type==1)
        {
            sz+=1;
            ll k=divisor.size();
            for (ll mask=1; mask<(1<<k); mask++)
            {
                ll p=1;
                for (ll j=0; j<k; j++) if (mask&(1<<j)) p*=divisor[j];
                if (__builtin_popcountll(mask)%2==1) ans+=cnt[p];
                else ans-=cnt[p];
                ++cnt[p];
            }          
        }
        else 
        {
            sz-=1;
            ll k=divisor.size();
            for (ll mask=1; mask<(1<<k); mask++)
            {
                ll p=1;
                for (ll j=0; j<k; j++) if (mask&(1<<j)) p*=divisor[j];
                --cnt[p];
                if (__builtin_popcountll(mask)%2==1) ans-=cnt[p];
                else ans+=cnt[p];
            }            
        }
        cout<<sz*(sz-1)/2-ans<<endl; 
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}