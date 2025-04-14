// Author: envy
// Problem: Problem 2. Tractor
// Attempted: 2021-11-26 10:54:07 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
struct DSU{
	vector<int> p, sz;
	DSU(int n){
		p.resize(n);
		sz.resize(n,1);
		iota(p.begin(),p.end(),0);
		
	}
	int get(int x){
		if(p[x] != x){
			p[x] = get(p[x]);
		}
		return p[x];
	}
	bool unite(int a, int b){
		a = get(a); b = get(b);
		if(sz[a] < sz[b])swap(a,b);
		if(a != b){
			p[b] = a;
			sz[a] += sz[b];
		}
		return sz[a] >= (p.size() +1)/2;
	}
	bool sameset(int a, int b){return get(a) == get(b);}
	int getsize(int a){return sz[get(a)];}
};
main(){
	ifstream cin("tractor.in");
	ofstream cout("tractor.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	int grid[n][n];
	for(int i =0; i <n; i++){
		for(int j = 0; j <n; j++){
			cin>>grid[i][j];
		}
	}
	vector<array<int,5>> edges;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < 4; k++){
				int r = dx[k] + i;
				int c = dy[k] + j;
				if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] > grid[i][j])continue;
				edges.push_back({grid[i][j] - grid[r][c],i,j,r,c});
			}
		}
	}
	DSU dsu(n*n);
	sort(edges.begin(),edges.end());
	for(auto i: edges){
		if(dsu.unite(i[1]*n + i[2], i[3] * n + i[4])){
			cout<<i[0];
			return 0;
		}
	}
	
}