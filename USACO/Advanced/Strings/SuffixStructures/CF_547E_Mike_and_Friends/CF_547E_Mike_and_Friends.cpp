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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
ll n, q, st[200005];
string s;
string t[200005];

struct segment_tree_vector
{
    ll n;
    vector<ll> arr;
    vector<vector<ll>> tree;
    segment_tree_vector(){}
    segment_tree_vector(ll _n, vector<ll> _arr)
    {
        n=_n;
        arr=_arr;
        tree.resize(4*n+5);
        build(1, 0, n);
    }
    vector<ll> opt(vector<ll> a, vector<ll> b)
    {
        ll i=0, j=0;
        vector<ll> v;
        while (i<a.size() && j<b.size())
        {
            if (a[i]<b[j]) v.push_back(a[i++]);
            else v.push_back(b[j++]);
        }
        while (i<a.size()) v.push_back(a[i++]);
        while (j<b.size()) v.push_back(b[j++]);
        return v;
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id].push_back(arr[l]);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
    ll query(ll id, ll l, ll r, ll u, ll v, ll k)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].size()-(lower_bound(tree[id].begin(), tree[id].end(), k)-tree[id].begin());
        ll mid=(l+r)/2;
        return query(id*2, l, mid, u, v, k)+query(id*2+1, mid+1, r, u, v, k);
    }
};

struct SuffixArray
{
    string s;
    ll n, alphabet, classes;
    vector<ll> cnt, c, sa, lcp, cur_c, cur_sa, rank;
    SuffixArray(){}
    SuffixArray(string _s)
    {
        s=_s+"$";
        n=s.size();
        alphabet=256;
        cnt.resize(max(alphabet, n)+5); c.resize(n+5); sa.resize(n+5); lcp.resize(n+5); cur_c.resize(n+5); cur_sa.resize(n+5); rank.resize(n+5);
        build_sa();
        // build_lcp();
    }

    void build_sa()
    {
        //sap sep randix (co so)
        fill(cnt.begin(), cnt.end(), 0);
        for (ll i=0; i<n; i++) 
            ++cnt[s[i]];
        for (ll i=1; i<alphabet; i++) 
            cnt[i]+=cnt[i-1];
        for (ll i=n-1; i>=0; i--)
            sa[--cnt[s[i]]]=i;
        c[sa[0]]=0;
        classes=0;
        for (ll i=1; i<n; i++) 
        {
            if (s[sa[i]]!=s[sa[i-1]]) ++classes;
            c[sa[i]]=classes;
        }

        for (ll h=0; (1LL<<h)<n; h++)
        {
            for (ll i=0; i<n; i++)
                cur_sa[i]=(sa[i]-(1LL<<h)+n)%n;  
            //chung ta can sap sep pair(c[sa[i]], c[(sa[i]+1LL<<h)%n) nhung thang second da duoc sap sep trong lan lap truoc 2^(k-1)
            //nen can sap sep theo thang first o do dai 2^k thi tru di (1LL<<h)
            fill(cnt.begin(), cnt.end(), 0);
            for (ll i=0; i<n; i++)
                ++cnt[c[cur_sa[i]]];
            for (ll i=1; i<=classes; i++)
                cnt[i]+=cnt[i-1];
            for (ll i=n-1; i>=0; i--)
                sa[--cnt[c[cur_sa[i]]]]=cur_sa[i];
            cur_c[sa[0]]=0;
            classes=0;
            for (ll i=1; i<n; i++)
            {
                pair<ll, ll> cur={c[sa[i]], c[(sa[i]+(1LL<<h))%n]};
                pair<ll, ll> pre={c[sa[i-1]], c[(sa[i-1]+(1LL<<h))%n]};
                if (cur!=pre) ++classes;
                cur_c[sa[i]]=classes;
            }
            swap(c, cur_c);
        }
    }

    void build_lcp()
    {
        //Kasai algorithm
        for (ll i=0; i<n; i++) rank[sa[i]]=i;
        ll k=0;
        for (ll i=0; i<n; i++)
        {
            if (rank[i]==n-1)
            {
                k=0;
                continue;
            }
            ll j=sa[rank[i]+1];
            while (i+k<n && j+k<n && s[i+k]==s[j+k]) ++k;
            lcp[rank[i]]=k;   //lcp(rank[i], rank[i]+1), luu y sa[0]="$"
            k=max(k-1, 0LL); 
        }
    }

    ll check(ll mid, ll index)
    {
        ll k=t[index].size(), m=n-sa[mid], idx;
        for (idx=0; idx<min(k, m); idx++) 
            if (t[index][idx]!=s[sa[mid]+idx]) break;
        if (idx==k) return 0;  //t la tien to cua s[sa[mid]..n-1], khong dung st.find(t)==0 vi O(n.m)
        if (t[index][idx]<s[sa[mid]+idx]) return -1;
        return 1;
    }

    ll lower_bound(ll idx)
    {
        ll l=0, r=n-1, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2, chk=check(mid, idx);  //tim chi so nho nhat trong suffix array ma t<=s[sa[i]..n-1] va t la tien to cua s[sa[i]..n-1]
            if (chk==0) ans=mid, r=mid-1;   //tim nho nhat nen r=mid-1
            else if (chk==-1) r=mid-1; 
            else l=mid+1;
        }
        return ans;  //luu y neu ans=-1 la khong tim thay
    }

    ll upper_bound(ll idx)
    {
        ll l=0, r=n-1, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2, chk=check(mid, idx);  //tim chi so lon nhat trong suffix array ma s[sa[i]..n-1]<=t va t la tien to cua s[sa[i]..n-1]
            if (chk==0) ans=mid, l=mid+1;   //tim lon nhat nen l=mid+1
            else if (chk==-1) r=mid-1; 
            else l=mid+1;
        }
        return ans;  //luu y neu ans=-1 la khong tim thay
    }
};  

pair<ll, ll> qry[200005];

void solve()
{
    cin>>n>>q;
    s="$";
    for (ll i=1; i<=n; i++) cin>>t[i];
    for (ll i=1; i<=n; i++)
    {
        for (char c: t[i]) s.push_back(c);
        s.push_back('$');
        st[i]=s.size()-1;
    }
    s.pop_back();
    SuffixArray sa(s);
    for (ll i=1; i<=n; i++) qry[i]={sa.lower_bound(i), sa.upper_bound(i)};
    n=s.size()+1;
    segment_tree_vector seg(n, sa.sa);
    // for (ll i=0; i<sa.n; i++) cout<<sa.sa[i]<<"  "<<sa.s.substr(sa.sa[i], sa.n-sa.sa[i])<<endl; cout<<endl<<endl;
    while (q--)
    {
        ll l, r, i; cin>>l>>r>>i;
        auto [x, y]=qry[i];
        cout<<seg.query(1, 0, n, x, y, st[l-1])-seg.query(1, 0, n, x, y, st[r])<<endl;
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