#include<bits/stdc++.h>
using namespace std;

long long tinh(long long k, long long x)
{ 
	if (x<=k) return x*(x+1)/2;
	if (x>=2*k) x=2*k-1;
	x=2*k-1-x;
	long long ans=k*k-x*(x+1)/2;
	return ans;
}

void solve()
{
	long long k, x, l, r, mid; 
	cin>>k>>x;
	l=0; r=2*k; 
	while (l<r)
	{ cout<<l<<" "<<r<<endl;
		long long mid=(l+r)/2;
		if (tinh(k, mid)>x) l=mid+1; else r=mid;
	}
	cout<<l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t; t=1;
	while (t--)
	{
		solve();
	}
	
	return 0;
}