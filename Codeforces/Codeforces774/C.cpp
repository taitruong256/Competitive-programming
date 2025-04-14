/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll luythua[100];

ll tinh(ll n)
{
    ll cnt=0, index=40;   
    for (ll i = 40; i >= 0; --i) if (n >= (1LL << i)) n -= (1LL << i), ++cnt;
    if (n==0) return cnt;
    else return 1e9;
}

void solve()
{
    ll n, ans=1e9; cin>>n;
    ll giaithua[100];
    giaithua[0]=1;
    giaithua[1]=1;
    for (ll i=2; i<=15; i++) giaithua[i]=giaithua[i-1]*i;
    for (ll i=0; i<=15; i++) if (giaithua[i]==n)
    {
        cout<<1<<endl;
        return;
    }
    
    set<pair<ll, ll>> st;
    for (ll i=0; i<(1<<15); i++)
    {
        ll s=0, cnt=0;
        for (ll j=0; j<15; j++) if (i&(1<<j) && giaithua[j]!=1 && giaithua[j]!=2) s+=giaithua[j], ++cnt;
        if (s<=n) st.insert({s, cnt});        
        //for (ll j=14; j>=0; j--) if (i&(1<<j)) cout<<1; else cout<<0; cout<<endl;
    }
   
    for (auto it: st) ans=min(ans, it.second+tinh(n-it.first));
    //for (auto it: st) cout<<it.first<<" "<<it.second<<endl;
    if (ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}