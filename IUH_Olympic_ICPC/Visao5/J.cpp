#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

void solve()
{
    deque<ll> dq;
    ll sle=0, schan=0, k;
    string s; cin>>s>>k;
    for (ll i=0; i<s.size(); i++) 
    {
        ll x=s[i]-'0';
        if (i%2==0) sle+=x;
        else schan+=x;
        dq.push_back(x);
    }
    for (ll i=1; i<=min((ll)s.size(), k); i++)
    {
        ll x=dq.front(); dq.pop_front();
        swap(sle, schan);
        if (s.size()%2==1)
        {
            sle+=x;
            schan-=x;
        }
        if (abs(sle-schan)%11==0)
        {
            cout<<"YES";
            return;
        }
    }
    if (abs(sle-schan)%11==0)
    {
        cout<<"YES";
        return;
    }
    else 
    {
        cout<<"NO";
        return;
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