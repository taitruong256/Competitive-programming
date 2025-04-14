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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
char c[10][10];
pair<ll, ll> st, fi;
struct state 
{
    ll x, y, dir, dist;
    string path;

    bool operator > (const state other) const 
    {
        return this->dist>other.dist;
    }
};
ll d[10][10][10], dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
//0: phai
//1: duoi
//2: trai
//3: tren

bool check(ll x, ll y)
{
    if (1<=x && x<=8 && 1<=y && y<=8) return true;
    return false;
}

void solve()
{
    for (ll i=1; i<=8; i++) 
        for (ll j=1; j<=8; j++)
        {
            cin>>c[i][j];
            if (c[i][j]=='T') st={i, j}, c[i][j]='.';
            if (c[i][j]=='D') fi={i, j};
        }

    for (ll i=0; i<=8; i++)
        for (ll j=0; j<=8; j++)
            for (ll k=0; k<=8; k++)
                d[i][j][k]=1e18;

    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({st.first, st.second, 0, 0, ""});
    d[8][1][0]=0;
    while (!pq.empty())
    {
        auto [x, y, dir, dist, path]=pq.top(); pq.pop(); //cerr<<x<<" "<<y<<" "<<dir<<" "<<dist<<" "<<path<<endl;
        if (dist>d[x][y][dir]) continue;
        if (x==fi.first && y==fi.second)
        {
            cout<<path;
            return;
        }
        //di thang
        ll new_x, new_y, new_dir;
        new_x=x+dx[dir], new_y=y+dy[dir], new_dir=dir; 
        if (check(new_x, new_y)==true && (c[new_x][new_y]=='.' || c[new_x][new_y]=='D') && d[x][y][dir]+1<d[new_x][new_y][new_dir])
        {       
            d[new_x][new_y][new_dir]=d[x][y][dir]+1;
            pq.push({new_x, new_y, new_dir, d[new_x][new_y][new_dir], path+"F"});
        }

        //dung laze dot tuong bang 
        new_x=x+dx[dir], new_y=y+dy[dir], new_dir=dir;
        if (check(new_x, new_y)==true && c[new_x][new_y]=='I' && d[x][y][dir]+2<d[new_x][new_y][new_dir])
        {              
            d[new_x][new_y][new_dir]=d[x][y][dir]+2;
            pq.push({new_x, new_y, new_dir, d[new_x][new_y][new_dir], path+"XF"});
        }

        //xoay phai
        new_x=x, new_y=y, new_dir=(dir+1)%4; 
        if (check(new_x, new_y)==true && (c[new_x][new_y]=='.' || c[new_x][new_y]=='I') && d[x][y][dir]+1<d[new_x][new_y][new_dir])
        {          
            d[new_x][new_y][new_dir]=d[x][y][dir]+1;
            pq.push({new_x, new_y, new_dir, d[new_x][new_y][new_dir], path+"R"});
        }

        //xoay trai
        new_x=x, new_y=y, new_dir=(dir+3)%4; 
        if (check(new_x, new_y)==true && (c[new_x][new_y]=='.' || c[new_x][new_y]=='I') && d[x][y][dir]+1<d[new_x][new_y][new_dir])
        {             
            d[new_x][new_y][new_dir]=d[x][y][dir]+1;
            pq.push({new_x, new_y, new_dir, d[new_x][new_y][new_dir], path+"L"});
        }
    }
    cout<<"no solution";
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