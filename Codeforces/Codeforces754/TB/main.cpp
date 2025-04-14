#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n; cin>>s;
        string t=s;
        sort(t.begin(), t.end());  cout<<t<<endl;
        vector<int> vitri;
        for (int i=0; i<n; i++) if (s[i]!=t[i]) vitri.push_back(i);
        if (vitri.size()==0) cout<<0<<endl;
        else
        {
            cout<<1<<endl;
            cout<<vitri.size()<<' ';
            for (int i=0; i<vitri.size(); i++) cout<<vitri[i]+1<<' ';
            cout<<endl;
        }
    }
    return 0;
}
