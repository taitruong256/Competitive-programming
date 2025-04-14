#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, c;
    cin>>n>>c;
    long long a[n+1], s=0;
    bool co=false;
    for (long long i=0; i<n; i++)
    {
        cin>>a[i];
        s+=a[i];
        if (s>=c)
        {
            co=true;
            break;
        }
    }
    if (co==true) cout<<"YES"; else cout<<"NO";
    return 0;
}
