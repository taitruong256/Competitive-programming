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
ll n, m, x;
string s;

struct segment_tree
{
  struct node { ll pref, suff, mx, len; };
  vector<node> tree;
  ll n;

  node merge(node a, node b)
  {
    node new_node;
    new_node.pref=(a.pref==a.len)?a.pref+b.pref:a.pref;
    new_node.suff=(b.suff==b.len)?a.suff+b.suff:b.suff;
    new_node.mx=max({a.mx, b.mx, a.suff+b.pref});
    new_node.len=a.len+b.len;
    return new_node;
  }

  segment_tree(){}
  segment_tree(ll _n)
  {
    n=_n;
    tree.resize(4*n+5);
  }

  void update(ll id, ll l, ll r, ll pos, ll v)
  {
    if (l>pos || r<pos) return;
    if (pos<=l && r<=pos) 
    {
      tree[id]={v, v, v, 1};
      return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, pos, v);
    update(id*2+1, mid+1, r, pos, v);
    tree[id]=merge(tree[id*2], tree[id*2+1]);
  }

  void debugs(ll id, ll l, ll r)
  {
    if (l==r)
    {
      cout<<l<<" "<<tree[id].mx<<endl;
      return;
    }
    ll mid=(l+r)/2;
    debugs(id*2, l, mid);
    debugs(id*2+1, mid+1, r);
  }
};

void solve()
{
    cin>>s; n=s.size(); s=" "+s;
    segment_tree seg0(n), seg1(n);
    for (ll i=1; i<=n; i++)
    {
      if (s[i]=='0')
      {
        seg0.update(1, 1, n, i, 1);
        seg1.update(1, 1, n, i, 0);
      }
      else 
      {
        seg0.update(1, 1, n, i, 0);
        seg1.update(1, 1, n, i, 1);
      }
    }

    cin>>m;
    while (m--)
    {
      cin>>x;
      if (s[x]=='0')
      {
        seg0.update(1, 1, n, x, 0);
        seg1.update(1, 1, n, x, 1);
        s[x]='1';
      }
      else
      {
        seg0.update(1, 1, n, x, 1);
        seg1.update(1, 1, n, x, 0);
        s[x]='0';
      }
      cout<<max(seg0.tree[1].mx, seg1.tree[1].mx)<<" ";
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