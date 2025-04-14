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
};  