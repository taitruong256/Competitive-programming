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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct Lichao_tree  //luu y bo nho n.logn nen de toan cuc 
{
    struct line 
    {
        ll a, b;
        ll get(ll x) {return a*x+b;}
    };

    struct node 
    {
        line L;
        node *leftchild, *rightchild;
    
        node()
        {
            L={0, LLONG_MAX};
            leftchild=rightchild=NULL;
        }
    
        ~node()
        {
            delete leftchild;
            delete rightchild;
        }
    };
    ll minn, maxn;
    node *root=new node();
 
    Lichao_tree(){}
    Lichao_tree(ll _minn, ll _maxn)
    {
        minn=_minn;
        maxn=_maxn;
    }
    
    void extend(node *root, ll l, ll r)
    {
        if (l!=r)
        {
            if (root->leftchild==NULL) root->leftchild=new node();
            if (root->rightchild==NULL) root->rightchild=new node();
        }
    }
    
    void insert(node *root, ll l, ll r, line newL)
    {
        if (l>r) return;
        if (l==r)
        {
            if (newL.get(l)<root->L.get(l)) root->L.get(l);
            return;
        }
        extend(root, l, r);
        ll mid=(l+r)/2;
        bool le=newL.get(l)<root->L.get(l);
        bool mi=newL.get(mid)<root->L.get(mid);
        if (mi==true) swap(root->L, newL);
        if (le!=mi) insert(root->leftchild, l, mid, newL);
        else insert(root->rightchild, mid+1, r, newL);
    }
    
    ll query(node *root, ll l, ll r, ll x)
    {
        if (l>r) return LLONG_MAX;
        if (l==r) return root->L.get(x);
        extend(root, l, r);
        ll mid=(l+r)/2;
        if (x<=mid) return min(root->L.get(x), query(root->leftchild, l, mid, x));
        return min(root->L.get(x), query(root->rightchild, mid+1, r, x));
    }
 
    void insert(ll a, ll b)
    {
        line newL={a, b};
        insert(root, minn, maxn, newL);
    }

    ll query(ll x)
    {
        return query(root, minn, maxn, x);
    }
};
Lichao_tree seg(-1e18, 1e18);         //chinh lai minn va maxn
 
ll q, c;
void solve()
{
    ll n, q, a, b, x, type; cin>>n>>q;  
    for (ll i=0; i<n; i++) cin>>a>>b, seg.insert(a, b);
    // while (q--)
    // {
    //     cin>>type;
    //     if (type==0) 
    //     {
    //         cin>>a>>b;
    //         seg.insert(a, b);
    //     }
    //     else 
    //     {
    //         cin>>x;
    //         cout<<seg.query(x)<<endl;
    //     }
    // }
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