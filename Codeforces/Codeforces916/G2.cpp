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
const ll mod = 998244353;
mt19937_64 rnd(98275314);

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
        build(1, 1, n);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void build(ll id, ll l, ll r)
    {
        lazy[id]=-1;
        if (l==r)
        {
            tree[id]=1;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        if (t!=-1)
        {
            tree[id*2]=0;
            lazy[id*2]=0;
            tree[id*2+1]=0;
            lazy[id*2+1]=0;
            lazy[id]=-1;
        }
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]=0;
            lazy[id]=0;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    /*
    Co n bong den va co 2n mau phan biet. Ban dau tat ca deu tat
    Ban duoc thuc hien 2 thao tac sau bat ky so lan:
        -chon 2 bong i va j cung mau va co 1 bong sang, bat bong con lai
        -chon 3 bong i, j, k sao cho i va k cung mau va dang bat, bat bong den j
    Hoi:
        -kich thuoc tap hop nho nhat sao cho thuc hien 2 thao tac tren bat ky so lan tat ca deu bat
        -so cach chon tap hop tren.
    
    Loi giai:
    Nhan xet: 
        -kich thuoc tap toi thieu bang so doan lien tiep ma tat ca dong den deu xuat hien 0 hoac 2 lan
        -so cach chon bang tich cua so bong den tung doan
        *tuy nhien: trong doan co the long doan khac, ta phai danh dau de khong chon doan ben trong. dung segment tree de thuc hien
    */
    ll n; cin>>n;
    ll col[2*n+5];
    for (ll i=1; i<=2*n; i++) cin>>col[i];
    ll val[2*n+5];
    for (ll i=1; i<=n; i++) val[i]=rnd();  //khong dung rand()
    ll xr=0, ans=1, sz=0;
    map<ll, ll> pre;
    vector<ll> d(2*n+5);
    segment_tree_lazy seg(2*n);
    pre[0]=0;
    for (ll i=1; i<=2*n; i++)
    {
        xr^=val[col[i]];
        if (xr==0)  //doan co tat ca bong den xuat hien 0 hoac 2 lan 
        {
            ++sz;
            ll cnt=seg.query(1, 1, 2*n, pre[xr]+1, i);
            ans=(ans*cnt)%mod;
        }
        else if (pre.find(xr)!=pre.end())  //doan long ben trong
        {
            seg.update(1, 1, 2*n, pre[xr]+1, i, 0);
        }
        pre[xr]=i;   
    }     
    cout<<sz<<" "<<ans<<endl;
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