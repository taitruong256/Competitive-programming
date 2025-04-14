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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
vector<ll> cnt(30);

ll calc_sum(set<char> st)
{
    ll s=0;
    for (auto i: st) s+=cnt[i-'a'];
    return s;
}

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s; s=" "+s+"@";
    string t; cin>>t; t=" "+t+"#";

    for (ll i=0; i<30; i++) cnt[i]=0;
    ll ans_l=1, ans_r=k, max_length=-1, max_sum=0, diff=0, l=1;
    set<char> ans_Q, Q;

    for (ll r=1; r<=n; r++)
    {     
        if (s[r]!=t[r])
        {
            ++cnt[s[r]-'a'];
            if (cnt[s[r]-'a']==1) 
            {
                ++diff;
                Q.insert(s[r]);
            }
        }

        while (l<r && diff>k)
        {
            --cnt[s[l]-'a']; 
            if (cnt[s[l]-'a']==0)
            {
                --diff;
                Q.erase(s[l]);
            }
            ++l;
        }

        if (diff<=k)
        {
            if (r-l+1>max_length)
            {
                ans_l=l;
                ans_r=r;
                max_length=r-l+1;
                max_sum=calc_sum(Q);
                ans_Q=Q;
            }
            else if (r-l+1==max_length)
            {
                ll s=calc_sum(Q);
                if (s>max_sum)
                {
                    ans_l=l;
                    ans_r=r;
                    max_length=r-l+1;
                    max_sum=calc_sum(Q);
                    ans_Q=Q;
                }
            }
        }
    }

    for (ll i=1; i<=n; i++)
    {
        if (ans_Q.find(s[i])!=ans_Q.end())
        {
            s[i]=t[i];
        }
    } 

    ll ans=0, sum=0;
    for (ll i=1; i<=n+1; i++)
    {
        if (s[i]==t[i]) ++sum;
        else 
        {
            ans+=sum*(sum+1)/2;
            sum=0;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}