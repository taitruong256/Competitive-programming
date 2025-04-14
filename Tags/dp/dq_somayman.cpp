#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    string kq;
    for (int i=0; i<=n/4; i++)
    {
        if ((n-i*4)%7==0)
        {
            cout<<kq;
            for (int j=0; j<(n-i*4)/7; j++) cout<<7;
            return 0;
        }
        else kq=kq+'4';
    }
    cout<<-1;
    return 0;
}
