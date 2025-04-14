/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
pair<ll, ll> a[4005];

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

bool bs(ll l, ll r, pair<ll, ll> k)
{
    ll mid, t;           
    while (l<r)
    {
        mid=(l+r)>>1; 
        if (a[mid].first==k.first && a[mid].second==k.second)
        {
            t=mid; break;
        }
        else if (a[mid].first>k.first || (a[mid].first==k.first && a[mid].second>k.second)) 
            t=mid, r=mid;
        else l=mid+1;
    }                    
    return (a[t].first==k.first && a[t].second==k.second);
}

void solve()
{
    ll n; cin>>n;
    
    for (ll i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a, a+n, comp);
    //for (ll i=0; i<n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;

    ll ans=0;
    for (ll i=0; i<n-1; i++)
        for (ll j=i+1; j<n; j++)
        {        
            if ((a[i].first+a[j].first)%2!=0 || (a[i].second+a[j].second)%2!=0) continue; 
            if (bs(0, n, {(a[i].first+a[j].first)/2, (a[i].second+a[j].second)/2})) ++ans;
            pair<ll, ll> it={(a[i].first+a[j].first)/2, (a[i].second+a[j].second)/2};
            //cout<<it.first<<" "<<it.second<<endl;
        }
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}