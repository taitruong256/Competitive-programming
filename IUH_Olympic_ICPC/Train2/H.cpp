#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d;
    cin>>n>>m>>d;
    string s[1000001];
    bool danhdau[1000001]={true};
    for (int i=1; i<=n+m; i++) cin>>s[i];

    for (int i=1; i<=n+m; i++) if (danhdau[i]==true)
    {
        bool kt=false;
        for (int j=i+1; j<=n+m; j++) if (danhdau[j]==true && s[i]==s[j])
        {
            kt=true;
            danhdau[i]==false;
            danhdau[j]==false;
        }
        if (kt==true) cout<<"BAD\n"; else cout<<"GOOD\n";
    }
    return 0;
}
