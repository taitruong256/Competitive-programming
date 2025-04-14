#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
	long long n; cin>>n;
	long long a[2][n+1], dp[2][n+1];
	for (int i=1; i<=n; i++) cin>>a[0][i];
	for (int i=1; i<=n; i++) cin>>a[1][i];
	
	dp[0][0]=dp[1][0]=0;
	for (int i=1; i<=n; i++)
	{
		dp[0][i]=max(dp[0][i-1], dp[1][i-1]+a[0][i]);
		dp[1][i]=max(dp[1][i-1], dp[0][i-1]+a[1][i]);
	}
	cout<<max(dp[0][n], dp[1][n]);
	return 0;
}
