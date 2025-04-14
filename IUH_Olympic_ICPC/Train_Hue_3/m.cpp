/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x=0,y=0;
void eu(ll a,ll b){
    if(b==0){
        x=1;y=0;
    }else{
        eu(b,a%b);
        ll tmp=x;
        x=y;
        y=tmp-(a/b)*y;
    }
}
void solve()
{
   ll a,b,c; cin>>a>>b>>c;
//    if(a==0 && b==0){
//        cout<<"No"
//    }
   eu(a,b);
   cout<<x<<" "<<y<<endl;
     if(x<=1e18 && x>=-1e18 && y<=1e18 && y>=-1e18 ) {
         ll cp=-c/(a*x+b*y);
        //  cout<<cp<<endl;
         cout<<"Yes\n";
        cout<<cp*x<<" "<<cp*y;
   }else cout<<"No";

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