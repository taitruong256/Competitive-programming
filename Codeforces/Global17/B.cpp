#include<bits/stdc++.h>
using namespace std;

void xuli()
{
        int n, a, b;
        cin>>n>>a>>b;

        bool dau[10000]={true};
        for (int i=1; i<=10000; i++) dau[i]=true;
        int d=0, kq[10000];
        ++d;
        kq[d]=a;
        dau[a]=false;
        for (int i=n; d<=n/2-1; i--) if (i!=b)
        {
            ++d;
            kq[d]=i;
            dau[i]=false;
            if (i<a)
            {
                cout<<-1<<endl;
                return;
            }
        }

        ++d;
        kq[d]=b;
        dau[b]=false;
        for (int i=1; i<=n; i++) if (dau[i]==true)
        {
            ++d;
            kq[d]=i;
            dau[i]=false;
            if (i>b)
            {
                cout<<-1<<endl;
                return;
            }
        }

        for (int i=1; i<=n; i++) cout<<kq[i]<<" ";
        cout<<endl;
        return;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        xuli();
    }
    return 0;
}
