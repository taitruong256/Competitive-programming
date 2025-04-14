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
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

struct node 
{
    ll sum, lazy, mx;
    node *leftchild, *rightchild;

    node()
    {
        sum=0;
        lazy=-mod;
        mx=0;
        leftchild=rightchild=nullptr;
    }

    ~node()
    {
        delete leftchild;
        delete rightchild;
    }

    void extend(ll l, ll r)
    {
        if (l!=r)
        {
            if (leftchild==nullptr) leftchild=new node();
            if (rightchild==nullptr) rightchild=new node();
        }
    }

    void down(ll l, ll r)
    {
        if (lazy>-mod)
        {
            mx=sum=(r-l+1)*lazy;
            mx=max(0LL, mx);
            if (l!=r)
            {
                extend(l, r);
                leftchild->lazy=lazy;
                rightchild->lazy=lazy;
            }   
            lazy=-mod;
        }
    }

    void update(ll l, ll r, ll u, ll v, ll val)
    {
        down(l, r);
        if (l>v || r<u || u>v) return;   
        if (u<=l && r<=v) 
        {
            lazy=val;
            down(l, r);   
            return;
        }
        extend(l, r);
        ll mid=(l+r)/2;
        leftchild->update(l, mid, u, v, val);
        rightchild->update(mid+1, r, u, v, val);
        sum = leftchild->sum + rightchild->sum;  
        mx = max(leftchild->mx, leftchild->sum+rightchild->mx);  
    }

    ll query(ll l, ll r, ll h)
    {
        down(l, r);
        if (l==r)
        {
            if (h>=mx) return l;
            return l-1;
        }
        extend(l, r);
        ll mid=(l+r)/2;
        leftchild->down(l, mid);
        rightchild->down(mid+1, r);
        if (h<leftchild->mx) return leftchild->query(l, mid, h);
        return rightchild->query(mid+1, r, h-leftchild->sum);
    }
};

ll n;
node *root=new node();

void solve()
{
    cin>>n;
    while (true)
    {
        char c; cin>>c;
        if (c=='Q')
        {
            ll h; cin>>h;
            if (root->mx<=h) cout<<n<<endl;
            else cout<<root->query(1, n, h)<<endl;
        }
        else if (c=='I')
        {
            ll l, r, d; cin>>l>>r>>d;
            root->update(1, n, l, r, d);
        }
        else break;
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