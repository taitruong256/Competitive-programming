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
int cosan[3], gia[3], congthuc[3];
ll tien;

bool check(ll mid)
{
    ll tam=tien;
    for (ll i=0; i<3; i++) if (cosan[i]<mid*congthuc[i])
    {
        ll sl=mid*congthuc[i]-cosan[i];
        tam-=sl*gia[i];
    }
    // cout<<mid<<" "<<tam<<endl;
    return tam>=0;
}

void solve()
{
    string s; cin>>s;
    memset(congthuc, 0, sizeof(congthuc));
    for (auto c: s) if (c=='B') congthuc[0]++;
    for (auto c: s) if (c=='S') congthuc[1]++;
    for (auto c: s) if (c=='C') congthuc[2]++;
    for (ll i=0; i<3; i++) cin>>cosan[i];
    for (ll i=0; i<3; i++) cin>>gia[i];
    cin>>tien;


    // for (ll i=0; i<3; i++) cout<<congthuc[i]<<" "; cout<<endl;
    // for (ll i=0; i<3; i++) cout<<cosan[i]<<" "; cout<<endl;
    // for (ll i=0; i<3; i++) cout<<gia[i]<<" "; cout<<endl;


    ll l=0, r=1e14, ans=1e14;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
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