#include<bits/stdc++.h>
using namespace std;
using lld = long long;
 
void query(void){
	int n;
	cin >> n;
 
	vector<int> t(n);
	for(int& i : t)
		cin >> i;
 
	sort(t.begin(), t.end(), greater<int>());
	int x = t[0];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++)
			if(__gcd(x,t[i]) < __gcd(x,t[j]))
				swap(t[i],t[j]);
		x = __gcd(x,t[i]);
	}
 
	for(int i : t)
		cout << i << " ";
	cout << "\n";
}
 
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int q=1;
	cin >> q;
 
	while(q--)
		query();
 
	return 0;
}