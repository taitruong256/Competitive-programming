#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int b, p, f, h, c;
    cin>>b>>p>>f>>h>>c;
    int t1=min(b/2, p);  cout<<t1<<endl;
    int m1=t1*h;
    if (b-t1*2>=2) m1=m1+min((b-t1*2)/2, f)*c;

    int t2=min(b/2, f);   cout<<t2<<endl;
    int m2=t2*c;
    if (b-t2*2>=2) m2=m2+min((b-t2*2)/2, p)*h;

    cout<<max(m1, m2)<<endl;
    return;
}

int main() {                         system("cls");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
