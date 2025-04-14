/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int Block_size=320;
const int N=2e5+5;
int n, cnt[N/Block_size+2][N], a[N];

int query(int l, int r, int k)
{
    int blockL=(l+Block_size-1)/Block_size;
    int blockR=(r/Block_size);
    if (blockL>blockR) return count(a+l, a+r+1, k);

    int sum=0;
    for (int i=blockL; i<blockR; i++) sum+=cnt[i][k];
    for (int i=l; i<blockL*Block_size; i++) if (a[i]==k) ++sum;
    for (int i=blockR*Block_size; i<=r; i++) if (a[i]==k) ++sum;
    return sum;
}

void update(int pos, int val)
{
    int block=pos/Block_size;
    --cnt[block][a[pos]];
    a[pos]=val;
    ++cnt[block][a[pos]];
}

void solve()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n; i++) ++cnt[i/Block_size][a[i]];
    int q; cin>>q;
    while (q--)
    {
        ll l, r, k; cin>>l>>r>>k;
        cout<<query(--l, --r, k)<<endl;
    }
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