#include <bits/stdc++.h>
using namespace std;
 
string nhiphan(long long n)
{
    string s="";
    while (n>0)
    {
        if (n%2==0) s='0'+s; else s='1'+s;
        n=n/2;
    }
    return s;
}
 
bool kiemtra(string s1, string s2, long long n, long long k)
{
    while (s1.size()<n) s1='0'+s1;
    while (s2.size()<n) s2='0'+s2; // cout<<s1<<" "<<s2<<endl;
    long long d=0;
    for (long long i=n-1; i>=0; i--) 
    {
        if (s1[i]!=s2[i]) ++d;
        if (d>k) return false;
    }
    return true;
}
 
void solve()
{
    long long n, m, k;
    cin>>n>>m>>k;
    long long x[m+2], ans=0;
    for (long long i=1; i<=m+1; i++) cin>>x[i];
    string s=nhiphan(x[m+1]);
    for (long long i=1; i<=m; i++) if (kiemtra(nhiphan(x[i]), s, n, k)==true) ++ans;
    cout<<ans; 
    
    
    //cout<<endl;  cout<<s<<endl;
    //for (long long i=1; i<=m; i++) cout<<nhiphan(x[i])<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}