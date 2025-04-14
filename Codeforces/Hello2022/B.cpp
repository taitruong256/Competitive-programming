/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> dau={1e9+5, 1e9+5}, cuoi={0, 1e9+5};
    for (ll i=0; i<n; i++)
    {
      ll l, r, c; cin>>l>>r>>c;
      if (l<=dau.first && r>=cuoi.first) 
      {                                                cout<<"Truong hop 1"<<endl;
        if (l==dau.first && r==cuoi.first)
        {
          ll temp;
          if (dau.second==cuoi.second) temp=dau.second; 
          else temp=dau.second+cuoi.second;
          if (c<temp)
          {
            dau.second=cuoi.second=c;
            cout<<c<<endl;
            continue;
          }
        }

        dau.first=l;
        cuoi.first=r;
        dau.second=cuoi.second=c;
        cout<<c<<endl;
        continue;
      }
      else if ((l>=dau.first && r<cuoi.first) || (l>dau.first && r<=cuoi.first))
      {                                                  cout<<"Truong hop 2"<<endl;
        if (dau.second!=cuoi.second) cout<<dau.second+cuoi.second<<endl;
        else cout<<dau.second<<endl;
      }
      else if (l<=dau.first)
      {                                                      cout<<"Truong hop 3"<<endl;
        if (l==dau.first)
        {
          ll temp;
          if (dau.second==cuoi.second) temp=dau.second; 
          else temp=dau.second+cuoi.second;
          if (c<temp)
          {
            dau.second=c;
            cout<<dau.second+cuoi.second<<endl;
            continue;
          }
        }

        dau.first=l;
        dau.second=c;
        cout<<dau.second+cuoi.second<<endl;
        continue;
      }
      else if (r>=cuoi.first)
      {                                                      cout<<"Truong hop 4"<<endl;
        // if (r==cuoi.first)
        // {
        //   ll temp;
        //   if (dau.second==cuoi.second) temp=dau.second; 
        //   else temp=dau.second+cuoi.second;
        //   if (c<temp)
        //   {
        //     cuoi.second=c;
        //     cout<<dau.second+cuoi.second<<endl;
        //     continue;
        //   }
        // }

        cuoi.first=r;
        cuoi.second=c;
        cout<<dau.second+cuoi.second<<endl;
        continue;
      }
    }

    //cout<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}