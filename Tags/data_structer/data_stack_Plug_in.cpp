#include<bits/stdc++.h>
using namespace std;;

int main()
{
    string s; cin>>s;
    vector<char> q;
    for (int i=0; i<s.length(); i++)
    {
        if (!q.empty() && q.back()==s[i]) q.pop_back();
        else q.push_back(s[i]);
    }
    for (int i=0; i<q.size(); i++) cout<<q[i];
    return 0;
}
