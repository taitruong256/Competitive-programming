#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool co=false;
    for (int i=0; i<n; i++)
    {
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        if (abs(x2-x1)==abs(y2-y1))
        {
            co=true;
            break;
        }
    }
    if (co==true) cout<<"YES"; else cout<<"NO";
    return 0;
}
