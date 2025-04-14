#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    bool a[n+5];
    for (ll i=1; i<=n; i++)
    {
        char c; cin>>c;
        if (c=='T') a[i]=1;
        else a[i]=0;
    }
    vector<ll> st;
    char c;
    while (cin>>c)
    {
        ll x;
        if ('A'<=c && c<='Z') 
        {
            x=a[c-'A'+1];
            st.push_back(x);
        }
        else 
        {
            if (c=='*')
            {
                ll x=st.back(); st.pop_back();
                ll y=st.back(); st.pop_back();
                ll z=y&x;
                st.push_back(z);
            }
            else if (c=='+')
            {
                ll x=st.back(); st.pop_back();
                ll y=st.back(); st.pop_back();
                ll z=y|x;
                st.push_back(z);
            }
            else 
            {
                ll x=st.back(); st.pop_back();
                ll z=1-x;
                st.push_back(z);
            }
        }
    }
    assert(st.size()==1);
    if (st.back()==1) cout<<'T';
    else cout<<'F';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}