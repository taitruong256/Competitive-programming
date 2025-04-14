#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
string s; 
ll q; 

void solve()
{
    cin>>s;
    s=" "+s;
    cin>>q;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll pos; cin>>pos;
            char c; cin>>c;
            s[pos]=c;
        }
        else 
        {
            ll l, r; cin>>l>>r;
            ll cnt=1;
            for (ll i=l+1; i<=r; i++)
                if (s[i]!=s[i-1]) ++cnt;
            cout<<cnt/2<<endl;
        }
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