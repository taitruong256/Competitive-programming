/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, ans=0;
ll x[105];
bool d[105], dung[105];
vector<ll> v;
string s;

void check()
{
    string t=s;
    for (ll i=1; i<=k; i++) t+=to_string(v[x[i]]);
    ll x=0;
    for (ll i=0; i<t.size(); i++) x=x*10+(t[i]-'0');   //  cout<<x<<endl;
    if (x%11LL==0) ++ans;
}

void hoanvi(ll i)
{
    for (ll j=1; j<=k; j++) if (d[j]==false)
    {
        x[i]=j;
        d[j]=true;
        if (i==k) check();
        else hoanvi(i+1);
        d[j]=false;
    }
}

void solve()
{
    cin>>n>>m;
    s="";
    memset(d, false, sizeof(d));
    memset(dung, true, sizeof(dung));
    
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        s+=to_string(x);
        dung[x]=false;
    }  
    v.push_back(0);
    for (ll i=1; i<=n; i++) if (dung[i]==true) v.push_back(i);
    k=v.size()-1;
    hoanvi(1);
    cout<<ans;
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