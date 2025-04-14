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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
 
struct SuffixArray
{
    ll n;
    string s; 
    vector<ll> pos, rnk, lcp;
 
    SuffixArray(string _s)
    {
        s=_s+'$';
        n=s.size();
        pos.resize(n+5); rnk.resize(n+5); lcp.resize(n+5);
        buildSA();
        buildLCP();
    }
 
    void buildSA()
    {
        vector<ll> cnt(max(1LL*256, n));
        for (ll i=0; i<n; i++) ++cnt[s[i]];
        for (ll i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for (ll i=n-1; i>=0; i--) pos[--cnt[s[i]]]=i;
        for (ll i=1; i<n; i++) rnk[pos[i]]=rnk[pos[i-1]]+(s[pos[i]]!=s[pos[i-1]]);
        
        for (ll k=0; (1<<k)<n; k++)
        {
            vector<ll> npos(n+5), nrnk(n+5), ncnt(n+5);
            for (ll i=0; i<n; i++) pos[i]=(pos[i]-(1<<k)+n)%n;
            for (ll i=0; i<n; i++) ncnt[rnk[i]]++;
            for (ll i=1; i<n; i++) ncnt[i]+=ncnt[i-1];
            for (ll i=n-1; i>=0; i--) npos[--ncnt[rnk[pos[i]]]]=pos[i];
            for (ll i=1; i<n; i++)
            {
                pair<ll, ll> cur={rnk[npos[i]], rnk[(npos[i]+(1<<k))%n]};
                pair<ll, ll> pre={rnk[npos[i-1]], rnk[(npos[i-1]+(1<<k))%n]};
                nrnk[npos[i]]=nrnk[npos[i-1]]+(cur!=pre);
            }
            pos=npos; rnk=nrnk;
        }
    }

    void buildLCP()
    {
        s+=s;
        for (ll i=0, k=0; i<n-1; i++, k=max(k-1, 0LL))
        {
            ll j=pos[rnk[i]-1];
            while (s[i+k]==s[j+k]) ++k;
            lcp[rnk[i]-1]=k;
        }
    }

    string OrderSub(ll k)
    {
        for (ll i=1; i<n; i++)
        {
            ll nxt=n-1-pos[i]-lcp[i-1];
            if (k>nxt) k-=nxt;
            else return s.substr(pos[i], k+lcp[i-1]);
        }
    }
};
 
void solve()
{
    string s; cin>>s;
    SuffixArray sa(s);
    ll k; cin>>k;
    cout<<sa.OrderSub(k);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
