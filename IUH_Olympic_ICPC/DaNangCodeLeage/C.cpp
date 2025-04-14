#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

struct Matrix
{
    vector<vector<ll>> matrix;
    ll n, m;
    Matrix(){}
    Matrix(ll _n, ll _m)
    {
        n=_n;
        m=_m;
        matrix.resize(n+5);
        for (ll i=0; i<=n; i++) matrix[i].resize(m+5, 0);
    }
};

Matrix Identity(ll n)
{
    Matrix M(n, n);
    for (ll i=1; i<=n; i++) M.matrix[i][i]=1;
    return M;
}
 
Matrix operator* (Matrix A, Matrix B)
{
    assert(A.m==B.n);
    ll N=A.n, M=B.m, K=A.m;
    Matrix ans(N, N);
    for (ll i=1; i<=N; i++)
        for (ll j=1; j<=M; j++)
            for (ll k=1; k<=K; k++)
            {
                ans.matrix[i][j]+=A.matrix[i][k]*B.matrix[k][j];
                ans.matrix[i][j]%=mod;
            }
    return ans;
}
 
Matrix Power(Matrix A, ll k)
{
    Matrix ans=Identity(A.n);
    while (k>0)
    {
        if (k%2==1) ans=ans*A;
        A=A*A;
        k/=2;
    }
    return ans;
}
 
void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    ll n; cin>>n;

    Matrix X(1, 6);
    X.matrix[1][1]=0;
    X.matrix[1][2]=d;
    X.matrix[1][3]=c;
    X.matrix[1][4]=0;
    X.matrix[1][5]=b;
    X.matrix[1][6]=a;

    Matrix Y(6, 6);
    Y.matrix[1][1]=0;
    Y.matrix[1][2]=0;
    Y.matrix[1][3]=0;
    Y.matrix[1][4]=0;
    Y.matrix[1][5]=0;
    Y.matrix[1][6]=0;

    Y.matrix[2][1]=1;
    Y.matrix[2][2]=0;
    Y.matrix[2][3]=2;
    Y.matrix[2][4]=0;
    Y.matrix[2][5]=0;
    Y.matrix[2][6]=3;

    Y.matrix[3][1]=0;
    Y.matrix[3][2]=1;
    Y.matrix[3][3]=1;
    Y.matrix[3][4]=0;
    Y.matrix[3][5]=0;
    Y.matrix[3][6]=2;

    Y.matrix[4][1]=0;
    Y.matrix[4][2]=0;
    Y.matrix[4][3]=0;
    Y.matrix[4][4]=0;
    Y.matrix[4][5]=0;
    Y.matrix[4][6]=0;

    Y.matrix[5][1]=0;
    Y.matrix[5][2]=0;
    Y.matrix[5][3]=0;
    Y.matrix[5][4]=1;
    Y.matrix[5][5]=0;
    Y.matrix[5][6]=2;

    Y.matrix[6][1]=0;
    Y.matrix[6][2]=0;
    Y.matrix[6][3]=0;
    Y.matrix[6][4]=0;
    Y.matrix[6][5]=1;
    Y.matrix[6][6]=3;

    cout<<(X*Power(Y, n-1)).matrix[1][6];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    solve();
    // clock_t end = clock();
    // cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}