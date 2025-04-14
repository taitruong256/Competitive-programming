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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll maxn = (1LL<<20)+5;
bool used[maxn];
ll n, k; 
vector<ll> adj[maxn];
ll par[maxn], d[maxn];
ll z=0;

void genAdj(ll precnt, ll mask)
{
  ++z;
  if (z>1e7) return;
  ll new_mask;
  for (ll i=0; i<n; i++) 
  {
    ll bit=mask&(1LL<<i);  
    if (bit==0) new_mask=mask+(1LL<<i);   
    else new_mask=mask-(1LL<<i);   //dieu kien 3: khoang cach haming = 1
    ll cnt=__builtin_popcount(new_mask);   
    if (used[new_mask]==true) continue;;  //dieu kien 2: x[i]!=x[j]
    if (cnt>k) continue;  //dieu kien 1: x khong qua k bit 1
    adj[mask].push_back(new_mask);
    cnt+=__builtin_popcount(mask);
    used[new_mask]=true;
    if (cnt>=precnt) genAdj(cnt, new_mask);   //dieu kien 4 tong so bit cua x[i] va x[i+1] tang dan
    used[new_mask]=false;
  }
}

bool comp(ll i, ll j)
{
  return adj[i].size()<adj[j].size();
}

void bfs(ll s)
{
  queue<ll> q;
  par[s]=-1;
  q.push(s);
  while (!q.empty())
  {
    ll u=q.front(); q.pop();   //      printf("%lld %lld \n", u, par[u]);
    for (auto v: adj[u]) if (d[v]==0)
    {
      d[v]=d[u]+1;
      par[v]=u;
      q.push(v);
      break;
    }
  }
}

void solve(ll tc)
{
    string file_in="input_"+to_string(tc)+".txt"; 
    const char * file_input=file_in.c_str();
    freopen(file_input, "r", stdin);
    string file_out="output_"+to_string(tc)+".txt"; 
    const char * file_output=file_out.c_str();
    freopen(file_output, "w", stdout);
    scanf("%lld%lld", &n, &k);

    used[0]=true;
    genAdj(0, 0);
    for (ll i=0; i<(1LL<<n); i++) 
    {
      adj[i].resize(unique(adj[i].begin(), adj[i].end())-adj[i].begin());
      sort(adj[i].begin(), adj[i].end(), comp);
    }
    // for (ll i=0; i<(1LL<<n); i++)
    // {
    //   printf("%lld    ", i);
    //   for (auto j: adj[i]) printf("%lld ", j);
    //   printf("\n");
    // }
    bfs(0);
    ll mx=0;
    for (ll i=0; i<(1LL<<n); i++) if (d[i]>d[mx]) mx=i;
    // for (ll i=0;i<(1LL<<n); i++) printf(" %lld\n", d[i]); printf("mx = %lld\n", mx);

    vector<ll> ans;
    while (mx!=-1)
    {
      ans.push_back(mx);
      mx=par[mx];
    }
                             
    reverse(ans.begin(), ans.end());
    ll sz=ans.size();
    printf("%lld\n", sz);
    for (auto i: ans) 
    {
      for (ll j=0; j<n; j++)
        if (i&(1LL<<j)) printf("1");
        else printf("0");
      printf("\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; t=10;
    for (ll i=0; i<t; i++) solve(i);
    return 0;
}

