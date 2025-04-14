#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string filein, fileout;
const char *fin, *fout;
FILE *fi, *fo;
ll n;
vector<ll> adj[1005];
ll lable_bd[1005], lable_dfs[1005];
vector<ll> thutu;
vector<pair<ll, ll>> ans(1005);

void nhapxuatfile(ll tc)
{
    filein="input_"+to_string(tc)+".txt";
    fin = filein.c_str();
    fi=fopen(fin, "r");
    fileout="output_"+to_string(tc)+".txt";
    fout = fileout.c_str();
    fo=fopen(fout, "w");
}

void dfs(ll u, ll p)
{
    thutu.push_back(lable_dfs[u]);
    for (ll v: adj[u]) if (v!=p) dfs(v, u);
}

void solve(ll tc)
{
    ll n;
    fscanf(fi, "%lld", &n);
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; fscanf(fi, "%lld%lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) fscanf(fi, "%lld", &lable_bd[i]);

    vector<ll> p(n);
    for (ll i=1; i<=n; i++) p[i-1]=i;
    do 
    {
        for (ll i=1; i<=n; i++) lable_dfs[i]=lable_bd[i];
        for (ll i=1; i<=n-1; i++) 
        {
            thutu.clear();
            swap(lable_dfs[p[i-1]], lable_dfs[p[i]]);
            dfs(1, 1);
            bool check=true;
            for (ll i=0; i<n; i++) if (thutu[i]!=i+1) check=false;
            if (check==true && i<ans.size())
            {
                ans.clear();
                for (ll j=0; j<i; j++) ans.push_back({p[j], p[j+1]});
            }
        }
        for (auto i: p) cout<<i<<" "; cout<<"      "; for (auto i: thutu) cout<<i<<" "; cout<<endl;
    }
    while (next_permutation(p.begin(), p.end()));

    ll sz=ans.size();
    fprintf(fo, "%lld\n", sz);
    for (auto [u, v]: ans) fprintf(fo, "%lld %lld\n", u, v);

    for (ll i=1; i<=n; i++) adj[i].clear();
    ans.clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    for (ll i=0; i<t; i++) 
    {
        nhapxuatfile(i);
        solve(i);
    }
    return 0;
}