#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        int mx=0, sl=1;
        for (int i=1; i<n; i++)
        {
            if (s[i]==s[i-1]) ++sl;
            else mx=max(mx, sl), sl=1;
        }
        mx=max(mx, sl);
        cout<<mx+1<<endl;
    }
    return 0;
}