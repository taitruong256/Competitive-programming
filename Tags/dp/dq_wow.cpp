#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long q[1000005]={0}, ans=0, t=0, n=s.size();
    for (long long i=1; i<n; i++) q[i]=s[i]=='v' && s[i-1]=='v'?++t:t;
    for (long long i=0; i<n; i++) if (s[i]=='o') ans=ans+q[i]*(t-q[i]);
    cout<<ans;
    return 0;
}
