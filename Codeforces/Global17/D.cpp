#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b, x;
    cin>>a>>b>>x;
    while (b>0)
    {
         if (a>=x && (a-x)%b==0)
         {
             cout<<"YES"<<endl;
             break;
         }
         a=a%b;
         swap(a, b);
    }
    cout<<"NO"<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
