/*=====================================================================================
                Nothing is impossible, only you think it is impossible
                        Try, try, try again until you succeed
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0, n;
ll f[205], truoc[205], dau[205];
vector<pair<ll, ll>> a;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

void truyvet(ll i)
{           //  cout<<a[i].first<<" "<<a[i].second<<endl;

    if (i==-1) return;
    truyvet(truoc[i]);        // cout<<i<<" ";
    dau[i]=1;
}

void solve()
{
    cin>>n;
    a.resize(n+5);

    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    sort(a.begin()+1, a.begin()+n+1, cmp);

    memset(truoc, -1, sizeof (truoc));
    memset(dau, 0, sizeof(dau));
    for (ll i=1; i<=n; i++)
    {
        f[i]=1;
        for (ll j=1; j<i; j++) if (a[j].second<=a[i].first && f[j]+1>f[i])
        {
            f[i]=f[j]+1;
            truoc[i]=j;
        }
    }

    ll index=1;
    for (ll i=1; i<=n; i++) if (f[i]>f[index]) index=i;
    ans+=f[index];
    //for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;cout<<endl;cout<<endl;
    truyvet(index);
    for (ll i=1; i<=n; i++)
    {
        f[i]=1;
        for (ll j=1; j<i; j++) if (dau[i]==0 && a[j].second<=a[i].first && f[j]+1>f[i])
        {
            f[i]=f[j]+1;
            truoc[i]=j;
        }
    }

    index=1;
    for (ll i=1; i<=n; i++) if (f[i]>f[index] && dau[i]==0) index=i;
    ans+=f[index];
    //for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
    //truyvet(index);

    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
