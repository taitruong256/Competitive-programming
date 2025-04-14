#include <bits/stdc++.h>
using namespace std;
const int MAX=1000000000+9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int h[n+1];
        int gtmax=-1000000;
        for (int i=1; i<=n; i++) cin>>h[i];
        for (int i=1; i<=n; i++)
        {
            int j=i;
            while (h[j]>=h[i] && j>=1) --j;
            int k=i;
            while (h[k]>=h[i] && k<=n) ++k;  //cout<<i<<" "<<j<<endl;
            if (h[i]*(k-j-1)>gtmax) gtmax=h[i]*(k-j-1);
        }
        cout<<gtmax<<endl;
    }
    return 0;
}


