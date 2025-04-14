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
    string can[]={"giap", "at", "binh", "dinh", "mau", "ky", "canh", "tan", "nham", "quy"};
    string chi[]={"ti", "suu", "dan", "mao", "thin", "ty", "ngo", "mui", "than", "dau", "tuat", "hoi"};

    string a, b, c, d; cin>>a>>b>>c>>d;
    ll x, y, u, v;
    for (ll i=0; i<10; i++) if (can[i]==a) {x=i; break;}
    for (ll i=0; i<12; i++) if (chi[i]==b) {y=i; break;} 
    for (ll i=0; i<10; i++) if (can[i]==c) {u=i; break;}
    for (ll i=0; i<12; i++) if (chi[i]==d) {v=i; break;} 

    ll ans=0;
    for (ll i=0; i<1000; i++)
    {

                  //   cout<<can[(x+i)%10]<<" "<<chi[(y+i)%12]<<"                "<<c<<" "<<d<<endl;
        if (can[(x+i)%10]==c && chi[(y+i)%12]==d) break;
        ++ans;  
    }
    if (ans==1000) ans=-1;
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