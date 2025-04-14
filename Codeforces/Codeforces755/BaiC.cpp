#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    t=1; //cin>>t;
    while (t--)
    {
        int n, a[1000], b[1000];
        cin>>n;
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) cin>>b[i];
        sort(a, a+n);
        sort(b, b+n);
        bool co=true;
        for (int i=0; i<n; i++)
            if (a[i]+1==b[i] || a[i]==b[i]) continue;
            else
            {
                co=false;
                break;
            }
        if (co==true) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
