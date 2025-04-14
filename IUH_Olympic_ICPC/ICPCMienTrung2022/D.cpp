#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define  c cout<<"yes"<<endl;
#define endl '\n'
const int MAX=1e5;
vector<int>tree[MAX*4+5];
int arr[MAX+5];
void meger(vector<int> &a, vector<int> &b, vector<int> &ans){
    int i  = 0,j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]) ans.push_back(a[i]), i++;
        else {
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()) ans.push_back(a[i]), i++;
    while(j < b.size()) ans.push_back(b[j]), j++;
}

void buid(int id, int l ,int r){
    if(l == r){
        tree[id].push_back(arr[l]);
        return;
    }
    int mid = (l+r)/2;
    buid(id*2, l, mid);
    buid(id*2+1, mid+1, r);
    meger(tree[id*2], tree[id*2+1], tree[id]);
}
int getvl(int id, int l, int r, int &lx ,int &rx, int &val){
    if( l > rx || lx > r) return 0;
    if( l >= lx && r<=rx) return (upper_bound(tree[id].begin(), tree[id].end(), val)-tree[id].begin());
    int mid= (l+r)/2;
    return getvl(id*2, l, mid, lx, rx, val)+getvl(id*2+1, mid+1, r, lx, rx, val);
}
void solve()
{
    int n, q; cin>>n>>q;
    for(int i  =1; i<=n; i++){
        cin>>arr[i];
    }
    buid(1, 1, n);
    int low, hight, mid, l, r, pos, ans;
    while(q-- ){
        l, r; cin>>l>>r;
        pos=(l+r)/2-l+1;
        low=1, hight=100000, ans=100000;
        while (low<=hight)
        {
            mid=(low+hight)/2;
            if (getvl(1, 1, n, l, r, mid)>=pos) ans=mid, hight=mid-1;
            else low=mid+1;
        }
        cout<<ans<<endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
      solve();
   return 0;
}
