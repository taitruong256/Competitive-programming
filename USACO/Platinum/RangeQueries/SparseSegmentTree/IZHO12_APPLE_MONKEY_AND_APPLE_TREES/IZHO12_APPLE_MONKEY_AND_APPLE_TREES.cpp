/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
const ll mod = 1e9+7;

struct node 
{
    ll sum, lazy;
    node *leftchild, *rightchild;

    node()
    {
        sum=0;
        lazy=0;
        leftchild=rightchild=nullptr;
    }

    ~node()
    {
        delete leftchild;
        delete rightchild;
    }
};
node *root=new node();

void extend(node *root, ll l, ll r)
{
    if (l!=r)
    {
        if (root->leftchild==nullptr) root->leftchild=new node();
        if (root->rightchild==nullptr) root->rightchild=new node();
    }
}

void down(node *root, ll l, ll r)
{
    if (root->lazy!=0)
    {
        root->sum=(r-l+1)*root->lazy;
        if (l!=r)
        {
            extend(root, l, r);
            root->leftchild->lazy=root->lazy;
            root->rightchild->lazy=root->lazy;
        }   
        root->lazy=0;
    }
}

void update(node *root, ll l, ll r, ll u, ll v, ll val)
{
    down(root, l, r);
    if (l>v || r<u || u>v) return;   
    if (u<=l && r<=v) 
    {
        root->lazy=val;
        down(root, l, r);   
        return;
    }
    extend(root, l, r);
    ll mid=(l+r)/2;
    update(root->leftchild, l, mid, u, v, val);
    update(root->rightchild, mid+1, r, u, v, val);
    root->sum = root->leftchild->sum + root->rightchild->sum;  
}

ll query(node *root, ll l, ll r, ll u, ll v)
{
    down(root, l, r);
    if (l>v || r<u || u>v) return 0;
    if (u<=l && r<=v) return root->sum;
    extend(root, l, r);
    ll mid=(l+r)/2;
    return query(root->leftchild, l, mid, u, v) + query(root->rightchild, mid+1, r, u, v);
}
ll q, c;

void solve()
{
    cin>>q;
    while (q--)
    {
        ll type, l, r; cin>>type>>l>>r; l+=c; r+=c; assert(l<=1e9 && r<=1e9);
        if (type==1) c=query(root, 1, 1e9, l, r), cout<<c<<endl;
        else update(root, 1, 1e9, l, r, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}