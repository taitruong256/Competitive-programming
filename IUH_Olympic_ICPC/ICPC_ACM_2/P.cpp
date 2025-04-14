#include<bits/stdc++.h>
using namespace std;

int dem(int a)
{ 
    if (a<0) return 10000000;
	int da=0;
	while (a%10==0 && a>0)
	{
		++da;
		a=a/10;
	}   
	return da;
}


int main()
{
	long long n; cin>>n;
	long long a[n+1][n+1];
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) cin>>a[i][j];
	
	long long p[n+1][n+1], f[n+1][n+1];
	for (int i=0; i<=n; i++) f[0][i]=1000000000000000;
	for (int i=0; i<=n; i++) f[i][0]=1000000000000000;
	f[1][1]=a[1][1];
	for (int i=2; i<=n; i++) f[1][i]=f[1][i-1]*a[1][i];
	for (int i=2; i<=n; i++) f[i][1]=f[i-1][1]*a[i][1];
	
	for (int i=2; i<=n; i++)
	for (int j=2; j<=n; j++) 
		if (!(f[i-1][j]*a[i][j]%2==0 && f[i-1][j]*a[i][j]%5==0)) f[i][j]=f[i-1][j]*a[i][j];
		else f[i][j]=f[i][j-1]*a[i][j];
		
	string kq;
	int i=n, j=n;
	while (i>=1 && j>=1)
	{    //cout<<i<<" "<<j<<" --- "<<f[i-1][j]<<" "<<f[i][j-1]<<"-----"<<dem(f[i-1][j])<<" "<<dem(f[i][j-1])<<endl;
		if (dem(f[i-1][j])<=dem(f[i][j-1]))
		{
			--i;
			kq="D"+kq;
		}
		else
		{
			--j;
			kq="R"+kq;
		}
	}
		
	cout<<dem(f[n][n])<<endl;
	for (int i=1; i<kq.size(); i++) cout<<kq[i];
	

	/*cout<<endl<<endl;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=n; j++) cout<<f[i][j]<<" ";
		cout<<endl;
	}*/
	return 0;
}
