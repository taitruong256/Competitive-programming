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

struct KMP 
{
    string s, t, x;  //tim so lan xuat hien cua s trong t
    ll n, m, k;
    vector<ll> pi;  //pi[i]=do dai tien to k lon nhat s[0:k-1] ma hau to ket thuc tai i s[i-k+1:k] 

    KMP(){}
    KMP(string _s, string _t)
    {
        s=_s;
        t=_t;
        x=_s+"#"+_t;
        n=s.size();
        m=t.size();
        k=x.size();
        precalc();
    }

    void precalc()
    {
        x=s;  //neu chi tinh s thi thay x=s;   
        k=x.size();
        pi.resize(k+5); 
        for (ll i=1; i<k; i++)
        {
            ll j=pi[i-1];
            while (j>0 && x[i]!=x[j]) j=pi[j-1];  //neu x[i]!=x[pi[i-1]] thi tim k lon nhat < j thoa man tinh chat cua pi 
            if (x[i]==x[j]) ++j;
            pi[i]=j;
        }
    }

    vector<ll> matching()
    {
        vector<ll> ans;
        for (ll i=n+1; i<k; i++) if (pi[i]==n) ans.push_back(i-n);  //neu tien to =n thi i-n la vi tri bat dau
        return ans;
    }   
};

void solve()
{
    ll k; cin>>k;
    string s; cin>>s;
    KMP kmp(s, s);
    ll dp[k+5], ans=0;
    for (ll i=1; i<=k; i++) 
    {
        if (kmp.pi[i-1]==0) kmp.pi[i-1]=i;
        dp[i]=kmp.pi[i-1];
        dp[i]=min(dp[i], dp[kmp.pi[i-1]]);
        ans+=i-dp[i];
    }
    cout<<ans;
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