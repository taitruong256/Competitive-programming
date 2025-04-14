#include <bits/stdc++.h>
using namespace std;
vector<int> z;

void solve()
{
    string s; cin>>s;
    int n=s.size();
    z.resize(n+5);
    for (int i=1, l=0, r=0; i<n; i++)
    {
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    vector<int> v;
    for (int i=0; i<n; i++) v.push_back(z[i]);
    sort(z.begin(), z.begin()+n);
//    for (int i=0; i<n; i++) cout<<z[i]<<" "; cout<<"\n";
    int q; cin>>q;
    for (int i=0; i<q; i++)
    {
        int l; cin>>l;
        int cnt=lower_bound(z.begin(), z.begin()+n, l)-z.begin();
        cnt=n-cnt+1;
        if (v[n-l]==l && cnt>=3) cout<<"YES "<<cnt<<"\n";
        else cout<<"NO\n";
    }
}
int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
   return 0;
}
