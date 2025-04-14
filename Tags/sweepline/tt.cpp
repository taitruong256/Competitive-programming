#include<bits/stdc++.h>
using namespace std;
vector<long long> v;

void solve()
{
    for (int i=1; i<=1000000000; i++) v.push_back(i);
 
    long long w, n; cin>>w>>n;
    long long x, y,sum = 0;
    while(n--){
        cin>>x>>y;
        sum+=x*y;
    }
    cout<<sum/w;
 
 
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie();
 
    solve();
 
}