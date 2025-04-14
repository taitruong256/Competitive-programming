#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b; cin>>a>>b;
    int ans=a;
    while (a>=b)
    {
        ans=ans+a/b;
        a=a/b+a%b;
    }
    cout<<ans;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
