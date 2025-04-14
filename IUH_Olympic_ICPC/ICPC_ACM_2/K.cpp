#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s, t; getline(cin, s); getline(cin, t);
	int ds[10000], dt[10000];
	for (int i=0; i<s.size(); i++) ++ds[s[i]];
	for (int i=0; i<t.size(); i++) ++dt[t[i]];
	for (int i='a'; i<='z'; i++) if (dt[i]>ds[i]) cout<<(char)i;
	return 0;
}
