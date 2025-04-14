#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while (t--)
    {
        ll t1, p1, t2, p2;
        cin>>t1>>p1>>t2>>p2;
        double ss=log10(t1*1.0/t2)+p1-p2;
        if (ss<0) cout<<"<\n";
        else if (ss==0) cout<<"=\n";
        else cout<<">\n";
    }
    return 0;
}