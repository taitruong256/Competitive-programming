/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll tinh(ll a, ll m)
{
    ll cnt1=0, temp=0;
    while (a>0) { 
        cnt1 += a;
        temp += a%m;   
        if (temp >= m) {
            a += temp/m;
            temp = temp%m;
        }
        a /= m;
    }
    return cnt1;
}
 
void solve()
{
    ll m, a, b; cin>>m>>a>>b;       
 
    ll t=1;
    while (tinh(t, m)<=b) t*=m;
    ll y=1;
    while (tinh(t, m)>=b) 
    {
        if (tinh(t, m)>=b) y-t;
        --t;
    }
    cout<<tinh(a, m)<<" "<<y;
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