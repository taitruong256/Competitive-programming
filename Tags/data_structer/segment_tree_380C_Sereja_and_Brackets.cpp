/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
struct node
{
    ll optimal, open, close;
    // node(){}
    node(ll opt, ll o, ll c)
    {
        optimal=opt; open=o; close=c;
    }
};
node tree[4000005] = node(0, 0, 0);
string s;

node operator + (const node &left, const node &right)
{
    ll temp=min(left.open, right.close);
    node res(0, 0, 0);
    res.optimal=left.optimal+right.optimal+temp;
    res.open=left.open+right.open-temp;
    res.close=left.close+right.close-temp;
    return res;
}

void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        if (s[l]=='(') tree[id]=node(0, 1, 0);
        else tree[id]=node(0, 0, 1);
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id]=tree[id*2]+tree[id*2+1];
}

node getvalue(ll id, ll l, ll r, ll u, ll v)
{
    if (r<u || l>v) return node(0, 0, 0);
    if (l>=u && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return getvalue(id*2,l,mid,u,v) + getvalue(id*2+1,mid+1,r,u,v);
}

void solve()
{
    cin>>s;
    s="@"+s;
    ll n=s.size();
    buildtree(1, 1, n);
    ll q; cin>>q;
    while (q--)
    {
        ll x, y; cin>>x>>y;
        cout<<2*getvalue(1, 1, n, x, y).optimal<<endl;
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