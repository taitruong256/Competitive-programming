#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        int l[n+1], r[n+1];
        for (int i=1; i<=n; i++) cin>>l[i]>>r[i];
        int time=0;
        for (int i=1; i<=n; i++)
        {
            time=max(time, l[i]);
            if (r[i]>=time) cout<<time++<<" "; else cout<<0<<" ";
        }
        cout<<endl;

    }
    return 0;
}
