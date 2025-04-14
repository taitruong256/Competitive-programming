#include<bits/stdc++.h>
using namespace std;

double min(double a, double b)
{
    return a<b?a:b;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double a, h,ans=0, tt=0;
	double hieusuat;
	cin >> a >> h;
	for (double i = 0; i <= h/6; i=i+1) {
		hieusuat = min(100, a/(h/6)*i);
		//cout <<setprecision(8)<<fixed<<hieusuat<< endl;
		tt = double((h-i)*hieusuat); printf("%.8f\n", tt);
		if (tt > ans) ans = tt;
	}
	for (double i = h/6; i <= h/3; i=i+1) {
		hieusuat = min(a+(100.0-a)/(h/6)*(i-h/6), 100);
        //cout <<setprecision(8)<<fixed<<hieusuat<< endl;
		tt = double((h-i)*hieusuat);  printf("%.8f\n", tt);
		if (tt > ans) ans = tt;
	}
	
	
}
