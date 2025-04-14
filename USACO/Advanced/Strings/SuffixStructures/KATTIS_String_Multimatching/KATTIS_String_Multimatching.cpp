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
        cnt.resize(max(alphabet, n)+5);
        c.resize(n+5);
        sa.resize(n+5);
        lcp.resize(n+5);
        cur_c.resize(n+5);
        cur_sa.resize(n+5);
        rank.resize(n+5);
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

    ll lower_bound(string t)
    {
        ll l=0, r=n-1, ans=-1;    
        while (l<=r)
        {
            ll mid=(l+r)/2; 
            if (s.substr(sa[mid], n-sa[mid])>=t) ans=mid, r=mid-1;
            else l=mid+1;      
        }
        return ans;
    }

    ll upper_bound(string t)
    {
        ll l=0, r=n-1, ans=-1;    
        t=t+"z";
        while (l<=r)
        {
            ll mid=(l+r)/2; 
            if (s.substr(sa[mid], n-sa[mid])<=t) ans=mid, l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};  
deque<string> dq;
string s;

ll convert(string s)
{
    ll ans=0;
    reverse(s.begin(), s.end());
    for (auto c: s) ans=(ans*10)+c-'0';
    return ans;
}

void solve()
{
    ll n=convert(dq.front()); dq.pop_front();
    string t[n+5];
    for (ll i=1; i<=n; i++) t[i]=dq.front(), dq.pop_front();
    string s=dq.front(); dq.pop_front();
    SuffixArray sa(s);
    for (ll i=1; i<=n; i++)
    {
        if (sa.lower_bound(t[i])==-1 || sa.upper_bound(t[i])==-1)
        {
            cout<<endl;
            continue;
        }
        vector<ll> v;
        for (ll j=sa.lower_bound(t[i]); j<=sa.upper_bound(t[i]); j++) v.push_back(sa.sa[j]);
        sort(v.begin(), v.end());
        for (auto j: v) cout<<j<<" ";
        cout<<endl;
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
    while (getline(cin, s)) dq.push_back(s);
    while (!dq.empty()) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}