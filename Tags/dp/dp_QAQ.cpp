#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int q[1000], ans=0, t=0, n=s.size();
    for (int i=0; i<n; i++) q[i]=s[i]=='Q'?++t:t;
    for (int i=0; i<n; i++) if (s[i]=='A') ans=ans+q[i]*(t-q[i]);
    cout<<ans;
    return 0;
}
