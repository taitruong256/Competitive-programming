/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{                           
  ll a, b, c, d, m; cin>>a>>b>>c;

  d=(c-b);   //nhan them a
  m=(b-d)/a;
  if (a*m==b-d && m>0)
  {                          //  cout<<"a  "<<m<<endl;
    cout<<"YES\n";
    return;
  }

  d=(c-a)/2;   //nhan them b
  m=(a+d)/b;
  if (b*m==a+d && m>0 && (c-a)%2==0) 
  {                         // cout<<"b  "<<m<<endl;
    cout<<"YES\n";
    return;
  }

  d=(b-a);   //nhan them c
  m=(b+d)/c;
  if (c*m==b+d && m>0)
  {                           // cout<<"c  "<<m<<endl;
    cout<<"YES\n";
    return;
  }

  cout<<"NO\n";
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1, d=0; cin>>t;
    while (t--) 
    {
      ++d;
      //cout<<"test case "<<d<<endl;
      solve();
    }
    return 0;
}
