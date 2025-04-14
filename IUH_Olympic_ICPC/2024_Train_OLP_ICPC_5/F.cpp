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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, q;
set<ll> pos;
set<tuple<ll, ll, ll>> seg;
map<ll, ll> pre, nxt;
ll qry[100005];
ll idx=0;

void solve()
{
    cin>>n>>q;
    while (q--)
    {
        char c; cin>>c;
        if (c=='+')
        {
            if (pos.size()==0)
            {
                qry[++idx]=1;
                cout<<qry[idx]<<endl;
                pos.insert(1);
            }
            else if (pos.size()==1)
            {
                ll x=*pos.begin();
                if (x-1>=n-x)
                {
                    qry[++idx]=1;
                    cout<<qry[idx]<<endl;
                    seg.insert({(x-1)/2, -1, -x});
                    pos.insert(1);
                    nxt[1]=x;
                    pre[x]=1;
                }
                else 
                {
                    qry[++idx]=n;
                    cout<<qry[idx]<<endl;
                    seg.insert({(n-x)/2, -x, -n});
                    pos.insert(n);
                    nxt[x]=n;
                    pre[n]=x;
                }
            }
            else 
            {
                auto [maxlen, l, r]=*seg.rbegin(); l=-l, r=-r;   
                // cerr<<"seg:    "; for (auto [mxlen, li, ri]: seg) cerr<<mxlen<<" "<<-li<<" "<<-ri<<"    "; cerr<<endl;
                ll ans=(l+r)/2;

                qry[++idx]=ans;
                cout<<qry[idx]<<endl;
                seg.erase({maxlen, -l, -r});
                seg.insert({(ans-l)/2, -l, -ans});
                seg.insert({(r-ans)/2, -ans, -r});
                pos.insert(ans);
                nxt[l]=ans;
                nxt[ans]=r;
                pre[ans]=l;
                pre[r]=ans;
            }
        }
        else 
        {
            ll k; cin>>k;  
            ll prek=k; 
            k=qry[k];
            qry[prek]=0;
            ll l=-1, r=-1;

            auto pr=pos.lower_bound(k);
            if (pr!=pos.begin()) 
            {
                --pr;
                l=*pr;
                seg.erase({(k-l)/2, -l, -k});
                pre[nxt[k]]=pre[k];
            }

            auto nx=pos.upper_bound(k);
            if (nx!=pos.end())
            {
                r=*nx;
                seg.erase({(r-k)/2, -k, -r});
                nxt[pre[k]]=nxt[k];
            }

            if (l!=-1 && r!=-1) seg.insert({(r-l)/2, -l, -r});

            pos.erase(k);
        }

        // for (auto i: pos) cerr<<i<<" "; cerr<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}