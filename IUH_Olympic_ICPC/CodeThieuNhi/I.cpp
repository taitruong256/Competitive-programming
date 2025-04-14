#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin>>s;
    int i=0;
    while (i<s.size())
    {
        if (s[i]=='1' && s[i+1]=='4' && s[i+2]=='4') i=i+3;
        else if (s[i]=='1' && s[i+1]=='4') i=i+2;
        else if (s[i]=='1' && s[i+1]!='4') i=i+1;
        else 
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
