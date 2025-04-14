#include <bits/stdc++.h>
using namespace std;

char doi(char c)
{
    if (c=='(') return ')';
    else if (c=='[') return ']';
    else return '}';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    stack<int> st;
    vector<pair<int, int>> matches;
    int n=s.size();
    bool kt=true;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            st.push(i);
        else
        {
            if (st.empty())
            {
                kt=false;
                break;
            }
            if (s[i]!=doi(s[st.top()]))
            {
                kt=false;
                break;
            }
            matches.push_back({st.top(), i});
            st.pop();
        }
    }
    if (!st.empty()) kt=false;
    if (kt==true)
    {
        cout<<"Yes";
        //for (int i=0; i<matches.size(); i++) cout<<matches[i].first<<" "<<endl;
    }
    else cout<<"No";
    return 0;
}


