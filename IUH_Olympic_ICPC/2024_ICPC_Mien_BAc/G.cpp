#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
string s;
ll pre[500005], nxt[500005], len[500005], num_block=0;

void solve()
{
    cin>>n;
    cin>>s;

    s="1"+s+"1";
    for (ll i=0; i<=n+1; i++) 
    {
        pre[i]=i-1;
        nxt[i]=i+1;
    }

    ll cnt=0;
    for (ll i=1; i<=n+1; i++) 
        if (s[i]=='0') ++cnt;
        else len[++num_block]=cnt, cnt=0;

    // for (ll i=1; i<=num_block; i++) cout<<len[i]<<" "; cout<<endl;

    ll ans=0;
    for (ll i=1; i<=n; i++) if (s[i]=='1') ++ans;
    set<pair<ll, ll>> st;
    for (ll i=1; i<=num_block; i++) st.insert({len[i], i});
    for (auto [x, y]: st) cout<<x<<" "<<y<<"     "; cout<<endl;
    for (ll size_block=1; size_block<=n+1; size_block++)
    {
        while (st.size()>1)
        {
            auto [min_len, min_pos]=*st.begin(); 
            if (min_len>=size_block) break;
            st.erase({min_len, min_pos});
            if (pre[min_pos]==0) 
            {
                ll nxt_min_pos=nxt[min_pos];
                auto [nxt_len, nxt_pos]=*st.lower_bound({len[nxt_min_pos], nxt_min_pos});
                st.erase({nxt_len, nxt_pos});
                st.insert({min_len+nxt_len, min_pos});
                nxt[pre[nxt_min_pos]]=nxt[nxt_min_pos];
                pre[nxt[nxt_min_pos]]=pre[nxt_min_pos];
                len[min_pos]+=len[nxt_min_pos];
            }
            else if (nxt[min_pos]>num_block)
            {                   
                ll pre_min_pos=pre[min_pos];
                auto [pre_len, pre_pos]=*st.lower_bound({len[pre_min_pos], pre_min_pos});
                st.erase({pre_len, pre_pos});
                st.insert({min_len+pre_len, min_pos});
                nxt[pre[pre_min_pos]]=nxt[pre_min_pos];
                pre[nxt[pre_min_pos]]=pre[pre_min_pos];
                len[min_pos]+=len[pre_min_pos];
            }
            else if (len[pre[min_pos]]<len[nxt[min_pos]]) 
            {
                ll pre_min_pos=pre[min_pos];
                auto [pre_len, pre_pos]=*st.lower_bound({len[pre_min_pos], pre_min_pos});
                st.erase({pre_len, pre_pos});
                st.insert({min_len+pre_len, min_pos});
                nxt[pre[pre_min_pos]]=nxt[pre_min_pos];
                pre[nxt[pre_min_pos]]=pre[pre_min_pos];
                len[min_pos]+=len[pre_min_pos];
            }
            else 
            {
                ll nxt_min_pos=nxt[min_pos];
                auto [nxt_len, nxt_pos]=*st.lower_bound({len[nxt_min_pos], nxt_min_pos});
                st.erase({nxt_len, nxt_pos});
                st.insert({min_len+nxt_len, min_pos});
                nxt[pre[nxt_min_pos]]=nxt[nxt_min_pos];
                pre[nxt[nxt_min_pos]]=pre[nxt_min_pos];
                len[min_pos]+=len[nxt_min_pos];
            }
        }
        ll size_set=st.size();
        if (size_set<=1) break;
        cout<<size_block*size_set+size_set-1<<"    "; for (auto [x, y]: st) cout<<x<<" "<<y<<"     "; cout<<endl;
        ans=max(ans, size_block*size_set+size_set-1);
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