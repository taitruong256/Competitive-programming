#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
 
struct Treap
{
    struct node
    {
        ll key, prior, size, rev, sum;
        node *left, *right;
        node () 
        {
            left=NULL;
            right=NULL;
        }
        node (ll _key)
        {
            key=_key;
            prior=rand();
            size=1;
            rev=0;
            sum=_key;
            left=NULL;
            right=NULL;
        }
    };
    node *Root=NULL;
 
    inline ll getsize(node *root)
    {
        if (root==NULL) return 0;
        return root->size;
    }
 
    inline ll getsum(node *root)
    {
        if (root==NULL) return 0;
        return root->sum;
    }
 
    void push_up(node *&root)
    {
        root->size=getsize(root->left)+getsize(root->right)+1;
        root->sum=getsum(root->left)+getsum(root->right)+root->key;
    }
 
    void push_down(node *&root)
    {
        if (root==NULL) return;
        if (root->rev==1)
        {
            root->rev=0;
            swap(root->left, root->right);
            if (root->left!=NULL) root->left->rev^=1;
            if (root->right!=NULL) root->right->rev^=1;
        }
    }
 
    void split(node *root, node *&left, node *&right, ll pos)
    {
        push_down(root);
        if (root==NULL)
        {
            left=right=NULL;
            return;
        }
        if (getsize(root->left)<pos)
        {
            split(root->right, root->right, right, pos-getsize(root->left)-1);
            left=root;
        }
        else 
        {
            split(root->left, left, root->left, pos);
            right=root;
        }
        push_up(root);
    }
 
    void merge(node *&root, node *left, node *right)
    {
        push_down(left);
        push_down(right);
        if (left==NULL) 
        {
            root=right;
            return;
        }
        if (right==NULL)
        {
            root=left;
            return;
        }
        if (left->prior>right->prior)
        {
            merge(left->right, left->right, right);
            root=left;
        }
        else 
        {
            merge(right->left, left, right->left);
            root=right;
        }
        push_up(root);
    }
 
    void insert(ll key)
    {
        node *new_node=new node(key);
        merge(Root, Root, new_node);
    }
 
    void update(node *root, ll l, ll r)
    {
        node *a, *b, *c, *d;
        split(Root, a, b, r);
        split(a, c, d, l-1);
        d->rev^=1;
        merge(Root, c, d);
        merge(Root, Root, b);
        push_up(root);
    }
 
    ll query(node *root, ll l, ll r, ll u, ll v)
    {
        push_down(root);
        if (l>r || root==NULL) return 0;
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return root->sum;
        ll mid=l+getsize(root->left), ans=0;
        if (u<=mid && mid<=v) ans+=root->key;
        return ans+query(root->left, l, mid-1, u, v)+query(root->right, mid+1, r, u, v);
    }
 
    void print(node *root)
    {
        if (root==NULL) return;
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
};
ll n, q, a[200005];
 
void solve()
{
    cin>>n>>q;
    Treap treap;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        treap.insert(a[i]);
    }
    while (q--)
    {
        ll type, l, r; cin>>type>>l>>r;
        if (type==1) treap.update(treap.Root, l, r);
        else cout<<treap.query(treap.Root, 1, n, l, r)<<endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}