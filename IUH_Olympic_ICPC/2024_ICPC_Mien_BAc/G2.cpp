#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
string s;
ll len[500005], num_block=0, pref[500005];

void solve()
{
    cin>>n;
    cin>>s;
    ll ans=0;
    for (ll i=0; i<n; i++) if (s[i]=='1') ++ans;
    deque<char> dq;
    for (auto c: s) dq.push_back(c);
    while (!dq.empty() && dq.front()=='1') dq.pop_front();
    while (!dq.empty() && dq.back()=='1') dq.pop_back();
    s="";
    for (auto c: dq) s.push_back(c);

    s="1"+s+"1";
    ll cnt=0, max_block=0;
    for (ll i=1; i<=n+1; i++) 
        if (s[i]=='0') ++cnt;
        else 
        {
            if (cnt>0) len[++num_block]=cnt, max_block=max(max_block, cnt);
            cnt=0;
        }
    for (ll i=1; i<=num_block; i++) pref[i]=pref[i-1]+len[i];
    pref[n+1]=pref[n];
    // for (ll i=1; i<=num_block; i++) cout<<len[i]<<" "; cout<<endl;
    // for (ll i=1; i<=num_block; i++) cout<<pref[i]<<" "; cout<<endl;

    // cout<<num_block<<endl;
    for (ll sz_block=1; sz_block<=n; sz_block++)
    {
        if (num_block==0) break;
        ll cnt_block=0;
        for (ll i=1; i<=num_block; i++)
        {
            ll next_pos=lower_bound(pref+i, pref+num_block+1, pref[i-1]+sz_block)-pref;
            if (pref[next_pos]-pref[i-1]>=sz_block) ++cnt_block;
            // cout<<i<<" "<<next_pos<<"   ";
            i=next_pos;
        }      
        // cout<<"    |   ";
        if (cnt_block==1) break;
        // cout<<"    |    "<<cnt_block<<"   "<<cnt_block*sz_block+cnt_block-1<<endl;
        ans=max(cnt_block*sz_block+cnt_block-1, ans);
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}