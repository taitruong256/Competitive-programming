#include <bits/stdc++.h>

using namespace std;

#define ll                          long long
#define fi                          first
#define se                          second
#define INF                         1e18
#define MOD                         1e9+7
#define FAST                        ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define pb                          push_back
#define debug(a)                    cout << #a <<" = "<< a << '\n'
#define scarr(a, n)                 for(auto i = 0; i < n; i++) cin >> a[i];
#define prarr(a, n)                 for(auto i = 0; i < n; i++) cout << a[i] << " ";
#define fori(i, a, b)                 for(auto i = int(a); i < int(b); i++)

// read-write file
#ifndef ONLINE_JUDGE 
#define RW                          freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout); 
#else
#define RW                          ;
#endif 

vector<ll> a, b, c;
vector<ll> tree;

// code
void buildTree(int id, int l, int r){
  if(l==r) {
    tree[id]=c[l-1];
    return;
  }
  
  int m = (l+r)/2;
  buildTree(id*2, l, m);
  buildTree(id*2+1, m+1, r);

  tree[id] = min(tree[id*2], tree[id*2+1]);
}

int getVal(int id, int l, int r, int u, int v){
  if(u>r || v<l) return 2*1e9+7;

  if(l>=u && r<=v) return tree[id];

  int m = (l+r)/2;
  return min(getVal(id*2, l, m, u, v), getVal(id*2+1, m+1, r, u, v));
}

void solve(){
    ll m, n, k, l, r, low; cin >> m >> n >> k;
    a.resize(m);
    b.resize(n);
    c.resize(m);
    tree.resize(m*4);
    fori(i, 0, m) cin >> a[i];
    fori(i, 0, n) cin >> b[i];
    sort(b.begin(), b.end());
    fori(i, 0, m){
        low = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        low=min(low, n-1);
        c[i]=min(abs(a[i]-b[low]), abs(a[i]-b[max(low-1, 0LL)]));;
    }
    buildTree(1, 1, m);
    while(k--){
        cin >> l >> r;
        cout << getVal(1, 1, m, l, r) << "\n";
    }
}

int main (){
    FAST;RW;
    solve();
    return 0;
}
