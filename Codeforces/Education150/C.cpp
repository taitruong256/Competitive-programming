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
ll n, suff[200005], cnt[10], pref[200005][10];
set<ll> pos[10];
map<char, ll> val;

void solve()
{
    string s; cin>>s;
    n=s.size(); s=" "+s;
    for (ll i=0; i<5; i++) pos[i].insert(0);
    for (ll i=1; i<=n; i++) pos[s[i]-'A'].insert(i);
    suff[n+1]=0;
    for (ll j=0; j<5; j++) cnt[j]=0, pref[0][j]=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<5; j++) pref[i][j]=pref[i-1][j];
        ++pref[i][s[i]-'A'];
    }
    for (ll i=n; i>=1; i--)
    {
        ll id=s[i]-'A', check=false;
        for (ll j=id+1; j<5; j++) if (cnt[j]>0) check=true;
        suff[i]=suff[i+1];
        if (check==false) suff[i]+=val[s[i]]; else suff[i]-=val[s[i]];
        ++cnt[id];
    }
    ll mx=-1e18;
    for (ll j=0; j<5; j++) cnt[j]=0;
    for (ll i=1; i<=n; i++)
    {
        char temp=s[i];
        pos[temp-'A'].erase(i);
        ++cnt[temp-'A'];
        for (ll j=0; j<5; j++)
        {
            //thay doi s[i] va tinh tu vi tri i den n
            s[i]=char(j+'A');
            pos[s[i]-'A'].insert(i);
            ll id=s[i]-'A', res=suff[i+1];
            bool check=false;
            for (ll k=id+1; k<5; k++) if (cnt[k]>0) check=true;
            if (check==false) res+=val[s[i]]; else res-=val[s[i]];

            ll posA=*lower_bound(pos[0].begin(), pos[0].end(), 0);
            ll posB=*lower_bound(pos[1].begin(), pos[1].end(), 0);
            ll posC=*lower_bound(pos[2].begin(), pos[2].end(), 0);
            ll posD=*lower_bound(pos[3].begin(), pos[3].end(), 0);
            ll posE=*lower_bound(pos[4].begin(), pos[4].end(), 0);

            

            pos[s[i]-'A'].erase(i);
        }
        s[i]=temp;
        pos[temp-'A'].insert(i);
    }
    cout<<mx<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    val['A']=1;
    val['B']=10;
    val['C']=100;
    val['D']=1000;
    val['E']=10000;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}