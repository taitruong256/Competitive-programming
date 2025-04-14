#include<bits/stdc++.h>
using namespace std;
long long INF=1ll<<32;

void solve()
{
    stack<long long> st;
    long long ans=0, l;
    st.push(1);
    cin>>l;
    while (l--)
    {
        string s; cin>>s;
        if (s=="add")
        {
            ans=ans+st.top();
            //cout<<"--top--"<<st.top()<<endl;;
        }
        else if (s=="for")
        {
            long long t; cin>>t;
            st.push(min(t*st.top(), INF));
        }
        else if (s=="end") st.pop();
    }
    if (ans>=INF) cout<<"OVERFLOW!!!"; else cout<<ans;
    return;
}

int main()
{
    solve();
    return 0;
}
