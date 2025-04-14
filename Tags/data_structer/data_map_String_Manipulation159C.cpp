#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
map<char, vector<ll>> mp;
bool dau[200005];
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
void solve()
{  
    ll pos; 
    char c;
    cin>>pos>>c;
    ll t=mp[c][pos-1];
    dau[t]=false;
    mp[c].erase(mp[c].begin()+pos-1);
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    string s, ss;
    memset(dau, true, sizeof(dau));
    ll k, n;
    cin>>k>>s;   
    for (ll i=0; i<k; i++) ss+=s;
    for (ll i=0; i<ss.size(); i++) mp[ss[i]].push_back(i);
    cin>>n;
    while (n--) solve();
    for (ll i=0; i<ss.size(); i++) if (dau[i]==true) cout<<ss[i];
    return 0;
}