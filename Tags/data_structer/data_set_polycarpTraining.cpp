#include<bits/stdc++.h>
using namespace std;
vector<string> s;
int main(){
	int n,cnt=1,a[200010]; cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i = 0;i < n;i++){
		if(a[i] >= cnt){
			cnt++;
		}
	}
	cout << cnt-1; 
}