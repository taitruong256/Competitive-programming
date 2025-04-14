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

struct Matrix
{
    ll n, m;
    ll matrix[2][2];
};

Matrix base={2, 2, 1, 1, 1, 0}, init={1, 2, 1, 0, 0, 0}, iden={2, 2, 1, 0, 0, 1}, tmp;

Matrix operator* (Matrix A, Matrix B)
{
    assert(A.m==B.n);
    ll N=A.n, M=B.m, K=A.m;
    Matrix ans{N, M, 0, 0, 0, 0};
    for (ll i=0; i<N; i++)
        for (ll j=0; j<M; j++)
            for (ll k=0; k<K; k++)
            {
                ans.matrix[i][j]+=A.matrix[i][k]*B.matrix[k][j];
                ans.matrix[i][j]%=mod;
            }
    return ans;
}

Matrix operator+ (Matrix A, Matrix B)
{
    assert(A.n==B.n && A.m==B.m);
    Matrix ans{A.n, A.m, 0, 0, 0, 0};
    for (ll i=0; i<A.n; i++)
        for (ll j=0; j<A.m; j++)
        {
            ans.matrix[i][j]=A.matrix[i][j]+B.matrix[i][j];
            ans.matrix[i][j]%=mod;
        }
    return ans;
}

Matrix Power(ll k)
{
    Matrix A=base;
    Matrix ans={2, 2, 1, 0, 0, 1};
    while (k>0)
    {
        if (k%2==1) ans=ans*A;
        A=A*A;
        k/=2;
    }
    return ans;
}

ll n, q, a[100005];

struct segment_tree_lazy
{
    vector<Matrix> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=init*Power(a[l]);
            lazy[id]=iden;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
        lazy[id]=iden;
    }

    void down(ll id)
    {
        Matrix t=lazy[id]; 
        tree[id*2]=tree[id*2]*t;    
        lazy[id*2]=lazy[id*2]*t;     
        tree[id*2+1]=tree[id*2+1]*t;  
        lazy[id*2+1]=lazy[id*2+1]*t;  
        lazy[id]=iden; 
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].matrix[0][1];
        ll mid=(l+r)/2;
        down(id);
        return (query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v))%mod;
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]=tree[id]*tmp; 
            lazy[id]=lazy[id]*tmp;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree_lazy seg(n);
    while (q--)
    {
        ll type; cin>>type; 
        if (type==1)
        {
            ll l, r, val; cin>>l>>r>>val;
            tmp=Power(val);       
            seg.update(1, 1, n, l, r, val);
        }
        else 
        {
            ll l, r; cin>>l>>r;     
            cout<<seg.query(1, 1, n, l, r)<<endl;
        }
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