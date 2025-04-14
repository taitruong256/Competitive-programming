/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double kiemtra(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a=y1-y2;
    ll b=x2-x1;
    ll c=-x1*a-y1*b; 
    ll t=a*x3+b*y3+c;
    if (t==0) return 0;
    else if (t<0) return -1;
    else return 1;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll x1, y1, x2, y2, x3, y3; 
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        ll th1=kiemtra(x1, y1, x2, y2, 0, 0);
        ll th2=kiemtra(x2, y2, x3, y3, 0, 0);
        ll th3=kiemtra(x3, y3, x1, y1, 0, 0);
        // cout<<th1<<" "<<th2<<" "<<th3<<endl;
        if (th1==th2 && th2==th3 && th1!=0) cout<<"Excellent\n";
        else if (th1*th2*th3==0) cout<<"Good\n";
        else cout<<"Bad\n";
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