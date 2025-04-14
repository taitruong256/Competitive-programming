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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
const ll mod = 1e9+7;

ll n, k;
ll gach[255][255];
vector<pair<ll, ll>> ans[40005];
ll dx[]={1, -1, 0, 0};
ll dy[]={0, 0, 1, -1};

ll rong(ll x, ll y)
{
    ll cnt=0;
    if (gach[x+1][y]==0) ++cnt;
    if (gach[x-1][y]==0) ++cnt;
    if (gach[x][y+1]==0) ++cnt;
    if (gach[x][y-1]==0) ++cnt;
    return cnt;
}

ll huong(ll x, ll y)
{
    if (gach[x+1][y]==0) return 0;
    if (gach[x-1][y]==0) return 1;
    if (gach[x][y+1]==0) return 2;
    return 3;
}

void solve()
{
    cin>>n>>k;
    ll cnt=0;
    for (ll i=0; i<=n*k+1; i++) gach[0][i]=gach[n*k+1][i]=-1;
    for (ll i=0; i<=n*k+1; i++) gach[i][0]=gach[i][n*k+1]=-1;

    // for (ll i=0; i<=n*k+1; i++)
    // {
    //     for (ll j=0; j<=n*k+1; j++) cout<<gach[i][j]<<" ";
    //     cout<<endl;
    // }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==4)
        {
            cout<<"ASK"<<" "<<i<<" "<<j<<endl;
            ++cnt;
            gach[i][j]=cnt;
            for (ll l=0; l<k-1; l++)
            {
                ll x, y; cin>>x>>y;
                gach[x][y]=cnt;
            }
        }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==1)
        {
            ++cnt;
            ll d=huong(i, j);
            ll x=i, y=j;
            gach[x][y]=cnt;
            for (ll l=0; l<k-1; l++) 
            {
                x=x+dx[d];
                y=y+dy[d];
                gach[x][y]=cnt;
            }
        }

    // for (ll i=0; i<=n*k+1; i++)
    // {
    //     for (ll j=0; j<=n*k+1; j++) cout<<gach[i][j]<<" ";
    //     cout<<endl;
    // }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==3)
        {
            cout<<"ASK"<<" "<<i<<" "<<j<<endl;
            ++cnt;
            gach[i][j]=cnt;
            for (ll l=0; l<k-1; l++)
            {
                ll x, y; cin>>x>>y;
                gach[x][y]=cnt;
            }
        }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==1)
        {
            ++cnt;
            ll d=huong(i, j);
            ll x=i, y=j;
            gach[x][y]=cnt;
            for (ll l=0; l<k-1; l++) 
            {
                x=x+dx[d];
                y=y+dy[d];
                gach[x][y]=cnt;
            }
        }

    // for (ll i=0; i<=n*k+1; i++)
    // {
    //     for (ll j=0; j<=n*k+1; j++) cout<<gach[i][j]<<" ";
    //     cout<<endl;
    // }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==2)
        {
            cout<<"ASK"<<" "<<i<<" "<<j<<endl;
            ++cnt;
            gach[i][j]=cnt;
            for (ll l=0; l<k-1; l++)
            {
                ll x, y; cin>>x>>y;
                gach[x][y]=cnt;
            }
        }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++) if (gach[i][j]==0 && rong(i, j)==1)
        {
            ++cnt;
            ll d=huong(i, j);
            ll x=i, y=j;
            gach[x][y]=cnt;
            for (ll l=0; l<k-1; l++) 
            {
                x=x+dx[d];
                y=y+dy[d];
                gach[x][y]=cnt;
            }
        }
    
    // for (ll i=0; i<=n*k+1; i++)
    // {
    //     for (ll j=0; j<=n*k+1; j++) cout<<gach[i][j]<<" ";
    //     cout<<endl;
    // }

    for (ll i=1; i<=n*k; i++)
        for (ll j=1; j<=n*k; j++)
            ans[gach[i][j]].push_back({i, j});
    
    cout<<"ANSWER"<<endl;
    for (ll i=1; i<=cnt; i++) 
    {
        for (auto [x, y]: ans[i]) cout<<x<<" "<<y<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}