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
const ll mod = 1e9+7;
const ll inf = 1e18;

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
        build_lcp();
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

    ll check(ll mid, string &t)
    {
        ll k=t.size(), m=n-sa[mid], idx;
        for (idx=0; idx<min(k, m); idx++) 
            if (t[idx]!=s[sa[mid]+idx]) break;
        if (idx==k) return 0;  //t la tien to cua s[sa[mid]..n-1], khong dung st.find(t)==0 vi O(n.m)
        if (t[idx]<s[sa[mid]+idx]) return -1;
        return 1;
    }

    ll lower_bound(string &t)
    {
        ll l=0, r=n-1, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2, chk=check(mid, t);  //tim chi so nho nhat trong suffix array ma t<=s[sa[i]..n-1] va t la tien to cua s[sa[i]..n-1]
            if (chk==0) ans=mid, r=mid-1;   //tim nho nhat nen r=mid-1
            else if (chk==-1) r=mid-1; 
            else l=mid+1;
        }
        return ans;  //luu y neu ans=-1 la khong tim thay
    }

    ll upper_bound(string &t)
    {
        ll l=0, r=n-1, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2, chk=check(mid, t);  //tim chi so lon nhat trong suffix array ma s[sa[i]..n-1]<=t va t la tien to cua s[sa[i]..n-1]
            if (chk==0) ans=mid, l=mid+1;   //tim lon nhat nen l=mid+1
            else if (chk==-1) r=mid-1; 
            else l=mid+1;
        }
        return ans;  //luu y neu ans=-1 la khong tim thay
    }
};  

void solve()
{
    string s; cin>>s;
    SuffixArray sa(s);
    ll q; cin>>q;
    string x="bab";
    while (q--)
    {
        string t; cin>>t;
        ll l=sa.lower_bound(t), r=sa.upper_bound(t);
        if (l==-1) cout<<0<<endl;
        else cout<<r-l+1<<endl;
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