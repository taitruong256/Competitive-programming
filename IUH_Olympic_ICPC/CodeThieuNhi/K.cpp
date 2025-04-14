#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, ans=0, t=1; cin>>n;
    while (n>0)
    {
        while (t<=n) t=t*2;
        t=t/2; 
        ++ans;
        n=n-t;  //cout<<n<<" "<<t<<endl;
        t=1;
    }
    cout<<ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}