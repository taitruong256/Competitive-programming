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

void debugg(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> cost)
{
  while (!cost.empty())
  {
    cout<<cost.top().first<<" "<<cost.top().second<<endl;
    cost.pop();
  }
}

void solve()
{
    ll n, q; cin>>n>>q;
    ll cnt[n+5], value[n+5];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> cost;
    for (ll i=1; i<=n; i++) cin>>cnt[i];
    for (ll i=1; i<=n; i++)
    {
      cin>>value[i];
      cost.push({value[i], i});
    }
    

    while (q--)
    {
      ll t, d; cin>>t>>d;
      ll sl=min(cnt[t], d);
      ll gia=sl*value[t];
      d-=sl;
      cnt[t]-=sl;
      while (!cost.empty() && d>0)
      {
        pair<ll, ll> temp=cost.top();   // cout<<"----"<<temp.first<<" "<<temp.second<<endl;
        cost.pop();
        sl=min(cnt[temp.second], d);
        gia+=sl*temp.first;
        d-=sl;
        cnt[temp.second]-=sl;
        if (cnt[temp.second]>0) cost.push({temp.first, temp.second});
      }  
      
      //for (ll i=1; i<=n; i++) cout<<cnt[i]<<" "; cout<<endl;
      //debugg(cost); cout<<endl;
      if (cost.size()==0 && d>0) cout<<0<<endl;
      else cout<<gia<<endl;
    }
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