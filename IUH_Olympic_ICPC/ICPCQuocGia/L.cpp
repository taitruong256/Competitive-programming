/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
bool prime[10000000];
vector<ll> v;
map<vector<ll>, ll> cnt;

vector<ll> chuyen(ll n)
{
    vector<ll> ans;
    ll i=0;
    while (n>1)
    {
        ll j;          
        for (j=i; j<v.size(); j++) if (n%v[j]==0) break;
        i=j;
        ans.push_back(v[j]);         
        while (n%v[j]==0) n/=v[j];      
        if (n==1) break;
    }
    return ans;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        vector<ll> temp=chuyen(x);
        for (ll j=0; j<temp.size(); j++) cout<<v[j]<<" "; cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif

    for (ll i=0; i<=1e7; i++) prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    for (ll i=2; i<=1e7; i++) if (prime[i]==true)
        for (ll j=2*i; j<=1e7; j+=i) prime[j]=false;
    for (ll i=2; i<=1e7; i++) if (prime[i]==true) v.push_back(i);

    solve();
    return 0;
}