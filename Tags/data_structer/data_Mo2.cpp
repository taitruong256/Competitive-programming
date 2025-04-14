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
const int Block_size=450;
const int N=2e5+5;
int n, lazy[N/Block_size+2][105], a[N];

void updateBlock(int l, int r, int oval, int nval)
{
    for (int i=l; i<=r; i++) a[i]=lazy[r/Block_size][a[i]];
    for (int i=1; i<=100; i++) lazy[r/Block_size][i]=i;
    for (int i=1; i<=100; i++) if (lazy[r/Block_size][i]==oval) lazy[r/Block_size][i]=nval;
}

void query(int l, int r, int oval, int nval)
{
    int blockL=(l+Block_size-1)/Block_size;
    int blockR=(r/Block_size);
    if (blockL>blockR)
    {
        updateBlock(l, r, oval, nval);
        return;
    }

    int sum=0;
    for (int i=blockL; i<blockR; i++)
        for (int j=1; j<=100; j++) if (lazy[i][j]==oval) lazy[i][j]=nval;
    updateBlock(l, blockL*Block_size-1, oval, nval);
    updateBlock(blockR*Block_size, r, oval, nval);
    return;
}

void solve()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) lazy[i/Block_size][a[i]]=a[i];
    int q; cin>>q;
    while (q--)
    {
        int l, r, x, y; cin>>l>>r>>x>>y;
        query(--l, --r, x, y);
        //for (int i=0; i<n; i++) a[i]=lazy[i/Block_size][a[i]];
        for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    }
    for (int i=0; i<n; i++) a[i]=lazy[i/Block_size][a[i]];
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
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