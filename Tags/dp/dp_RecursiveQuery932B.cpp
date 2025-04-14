#include "bits/stdc++.h"
using namespace std;
int dp[10][1000005];
 
int f(int x)
{
    if (x<10) return x;
    int t=1;
    while (x>0)
    {
        if (x%10!=0) t*=(x%10);
        x/=10;
    }
    return f(t);
}
 
void solve(){
	for (int i=1; i<1000001; i++) dp[f(i)][i]++;
 
    for (int i=1; i<10; i++)
        for (int j=1; j<1000001; j++) dp[i][j]+=dp[i][j-1];
 
    int n; cin>>n;
    while(n--)
    {
        int l, r, k; cin>>l>>r>>k;
        cout<<dp[k][r]-dp[k][l-1]<<"\n";
    }
    return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	solve();
	return 0;
}