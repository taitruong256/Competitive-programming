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
    vector<vector<ll>> matrix;
    ll n, m;
    Matrix(){}
    Matrix(ll _n, ll _m)
    {
        n=_n;
        m=_m;
        matrix.resize(n+5, vector<ll> (m+5, 0));
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
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    Matrix A(n, n);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            ll cnt=__builtin_popcountll(a[i]^a[j]);
            if (cnt%3==0) A.matrix[i][j]=1;
        }
    Matrix M=Power(A, k-1);
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            ans+=M.matrix[i][j];
            ans%=mod;
        }
    cout<<ans;
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