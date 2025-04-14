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
Cho một mảng a độ dài n-1. Hãy xây dựng mảng b độ dài n sao cho:
    -Mỗi số từ 0 đến n-1 xuất hiện chính xác 1 lần
    -Mỗi i từ 1 đến n-1, a[i]=b[i]^b[i+1]
Đáp án đảm bảo có một đáp án (hoán vị độ dài n từ 0 đến n-1).

Input
6
1 6 1 4 1
Output
2 3 5 4 0 1 

Ý tưởng:
Nhận xét:
    a[i]=b[i]^b[i+1]
    =>b[i]=b[i-1]^a[i-1] => b[i]=b[1]^a[1]^a[2]^..a[i-1]
    =>Giá trị đầu của mảng b quyết định toàn bộ mảng.
Chúng ta sẽ chạy for b1 từ 0 đến n-1, kiểm tra xem giá trị b1 có tạo được hoán vị hợp lệ hay không?
Đặt c[i]=a[1]^a[2]^...^a[i]. Lưu tất cả c[i] vào binary trie, kiểm tra xem giá trị lớn nhất của b1^c[i] có bằng n-1 hay không?
Lưu ý là đảm bảo c[i] là mảng riêng biệt vì c[i]=b[1]^b[i] (c[0]=0) nghĩa là mảng c là toàn bộ mảng b^b[1], đáp án đề bài đảm bảo 
có một đáp án mảng b là hoán vị nên không quan trọng b[1] có được chọn là bao nhiêu. 
Ta chỉ cần kiểm tra giá trị lớn nhất có bằng n-1 hay không thôi.
*/

struct BinaryTrie 
{
    struct node 
    {
        ll cnt, isEnd; //so tien to va so luong xau ket thuc 
        node *child[2];

        node()
        {
            cnt=isEnd=0;
            for (ll i=0; i<2; i++) child[i]=NULL;
        }
    };
    node *root=new node();
    ll lg=0;

    BinaryTrie(ll _maxvalue) 
    {
        ll v=1;
        while (v<_maxvalue/2) ++lg, v*=2;
    }

    string to_binary(ll n)
    {
        string s;
        for (ll i=lg; i>=0; i--) 
            if (n&(1LL<<i)) s.push_back('1');
            else s.push_back('0');
        return s;
    }

    void insert(ll _value)
    {
        string s=to_binary(_value); 
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'0';
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            p=p->child[nxt];
            p->cnt+=1;
        }
        p->isEnd+=1;
    }

    ll count(ll _value)  
    {
        string s=to_binary(_value);
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'0';
            if (p->child[nxt]==NULL) return 0;
            p=p->child[nxt];
        }
        return p->cnt;
    }

    ll getmax(ll _value)
    {
        string s=to_binary(_value);
        ll n=s.size(), ans=0;
        node *p=root;     
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'0';
            if (p->child[1-nxt]!=NULL) nxt=1-nxt, ans+=(1LL<<(lg-i));
            p=p->child[nxt];
        }
        return ans;
    }

    bool deleteRecursive(node *p, ll index, string &s)
    {
        if (index!=s.size())
        {
            ll nxt=s[index]-'0';  
            if (deleteRecursive(p->child[nxt], index+1, s)==true) p->child[nxt]=NULL;
        }   
        else p->isEnd-=1;
        if (p!=root)
        {
            p->cnt-=1;
            if (p->cnt==0) 
            {
                delete p;
                return true;
            }
        }
        return false;
    }

    bool deleted(ll _value)
    {
        string s=to_binary(_value);
        if (count(_value)==0) return false;
        return deleteRecursive(root, 0, s);
    }

    void travel(node *p, string s)
    {
        if (p==NULL) return;
        if (p->isEnd!=0)
            for (ll i=0; i<p->isEnd; i++) cerr<<s<<endl;
        for (ll i=0; i<2; i++) if (p->child[i]!=NULL) travel(p->child[i], s+char('0'+i));
    }

    void debug() { travel(root, ""); }
};

ll n, a[200005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n-1; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++) a[i]=(a[i-1]^a[i]);
    set<ll> st;
    for (ll i=0; i<=n-1; i++) st.insert(a[i]);
    assert(st.size()==n);
    BinaryTrie trie(2*n);
    for (ll i=0; i<=n-1; i++) trie.insert(a[i]);
    for (ll i=0; i<=n-1; i++) if (trie.getmax(i)==n-1) 
    {
        for (ll j=0; j<=n-1; j++) cout<<(a[j]^i)<<" ";
        return;
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