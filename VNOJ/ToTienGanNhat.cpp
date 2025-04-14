#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while (t--)
    {
        long long u, v;
        cin>>u>>v;
        while (u!=v)
        {
            if (u>v) u=u/2;
            else v=v/2;
        }
        cout<<u<<endl;
    }
    return 0;
}

