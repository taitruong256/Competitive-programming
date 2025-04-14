#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll parent[200005], rankk[200005];
vector<bitset<200005>> bits1(200005);
vector<bitset<200005>> bits2(200005);
ll cha(ll a)
{
    return a == parent[a] ? a : parent[a] = cha(parent[a]);
}

void hop(ll a, ll b)
{
    a= cha(a);
    b = cha(b);
    if(a != b)
    {
        if(rankk[a]<rankk[b]) swap(a, b);
        bits2[a] = bits2[a] | bits2[b];
        parent[b] = a;
        rankk[a] += (rankk[a] == rankk[b]);
    }
}

void solve()
{
    ll n, q; cin>>n>>q;
    for(ll i = 1; i <= n; i++) 
    {
        parent[i] = i;
        bits2[i][i] = 1;
    }
    while(q--)
    {
        ll t; cin>>t;
        if(t == 1)
        {
            ll u, v; cin>>u>>v;
            hop(u, v);
        }
        else if(t == 2)
        {
            ll u, v; cin>>u>>v;
            bits1[u][v] = 1;
            bits1[v][u] = 1;
        }
        else
        {
            ll id; cin>>id;
            ll ra = cha(id);
            cout<<(bits2[ra] & bits1[id]).count()<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}