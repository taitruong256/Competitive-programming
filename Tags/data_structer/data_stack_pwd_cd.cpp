#include<bits/stdc++.h>
using namespace std;
stack<string> st;

void solve(string s)
{
    if (s[0]=='/')
    {
        while (!st.empty()) st.pop();
        s.erase(0, 1);
    }
    s=s+'/';
    while (s.length()>0)
    {
        int pos=s.find('/');
        string tam=s.substr(0, pos);
        if (tam!="..") st.push(tam);
        else if(!st.empty()) st.pop();
        s.erase(0, pos+1);
    }
    return;
}

void show(stack<string> st)
{
    stack<string> t;
    while (!st.empty())
    {
        t.push(st.top());
        st.pop();
    }
    while (!t.empty())
    {
        cout<<"/"<<t.top();
        t.pop();
    }
    cout<<"/"<<endl;
    return;
}

int main()
{
    int n; cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        if (s=="cd") cin>>s;
        if (s=="pwd") show(st);
        else solve(s);
    }
    return 0;
}
