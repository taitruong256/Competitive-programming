#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin>>s;
    int m, d[10005]; cin>>m;
    d[0]=1;
    for (int i=1; i<s.size(); i++) if (s[i]==s[i-1]) d[i]=d[i-1]+1; else d[i]=1;
    for (int i=0; i<s.size(); i++) cout<<d[i]<<" ";

    for (int i=0; i<m; i++)
    {
        int l, r;
        cin>>l>>r;
        cout<<d[r]-d[l-1]<<endl;
    }
}
