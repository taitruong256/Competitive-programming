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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Van de:
Ban dau robot dung o vi tri (0, 0). Co n cau lenh thuoc 1 trong 4 loai U, D, L, R
Co q truy van, moi truy van hoi co the toi duoc diem (x, y) neu dao doan lenh [l, r] hay khong
Y tuong:
Goi pos[i] la vi tri cua robot sau cau lenh thu i (pos[0]={0, 0})
Moi truy van ta tach thanh 3 doan:
    -[0, l-1]: bat dau tu 0 vi ban dau co the chua diem (0, 0)
    -[l, r-1]: tu l den r-1 khong phai r vi co truong hop truy van l=r va (x, y)=pos[r] bi sai
    -[r, n]
Doi voi doan 1 va 3 thi kiem tra (x, y) co trong doan do khong
Doi voi doan 2 thi can tim vi tri pos[l-1]+pos[r]-pos[i]=(x, y)
                                =>pos[i]=pos[l-1]+pos[r]-(x, y). 
                                Dung lower de tim vi tri do va kiem tra xem co nam trong doan [l, r-1]
*/

map<pair<ll, ll>, vector<ll>> pts;

bool check(ll l, ll r, pair<ll, ll> p)
{
    if (pts.find(p)==pts.end()) return false;
    auto it=lower_bound(pts[p].begin(), pts[p].end(), l);
    if (it!=pts[p].end() && *it<=r) return true;
    return false;
}

void solve()
{
    ll n, q; cin>>n>>q;
    string s; cin>>s; s=" "+s;
    
    pair<ll, ll> now, pos[n+5];
    pos[0]={0, 0};
    pts[pos[0]].push_back(0);
    for (ll i=1; i<=n; i++)
    {
        if (s[i]=='L') now.first--;
        else if (s[i]=='R') now.first++;
        else if (s[i]=='U') now.second++;
        else now.second--;
        pts[now].push_back(i);
        pos[i]=now;
    }
    while (q--)
    {
        ll x, y, l, r; cin>>x>>y>>l>>r;
        ll newx=pos[l-1].first+pos[r].first-x, newy=pos[l-1].second+pos[r].second-y;
        if (check(0, l-1, {x, y})==true || check(l, r-1, {newx, newy})==true || check(r, n, {x, y})==true) 
            cout<<"YES\n";
        else 
            cout<<"NO\n";
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

