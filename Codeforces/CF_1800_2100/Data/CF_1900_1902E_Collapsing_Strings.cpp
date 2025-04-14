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
Cho n chuỗi s[1], s[2], ... s[n]. Gọi |x| là độ dài chuỗi x
Gọi C(a, b) của hai chuỗi a và b là:
    -Nếu a rỗng thì C(a, b)=b
    -Nếu b rỗng thì C(a, b)=a
    -Nếu ký tự cuối cùng của a bằng ký tự đầu tiên của b thì C(a, b)=C(a[1..|a|-1], b[2..|b|])
    -Ngược lại C(a, b)=a+b
Hãy tính C(s[i], s[j]) với 1<=i, j<=n.

Input
5
abab
babx
xab
xba
bab
Output
126

Ý tưởng:
Đầu tiên chúng ta đảo chuỗi a thay vì ký tự cuối cùng của a bằng ký tự đầu tiên của b.
C(a, b) = |a|+|b|-2*LCP(a, b)   LCP là độ dài tiền tố chung dài nhất của a và b.
Ta sẽ dùng Trie để lưu số lần xuất hiện của tiền tố đảo của mọi s[i].
*/

struct Trie 
{
    struct node 
    {
        ll cnt, isEnd; 
        node *child[26];

        node()
        {
            cnt=0;
            isEnd=false;
            for (ll i=0; i<26; i++) child[i]=NULL;
        }
    };
    node *root=new node();

    Trie() {}

    void insert(string s)
    {
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'a';
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            p=p->child[nxt];
            p->cnt+=1;
        }
        p->isEnd+=1;
    }

    ll count(string s) 
    {
        ll n=s.size();
        node *p=root;
        ll res=0;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'a';
            if (p->child[nxt]==NULL) break;
            p=p->child[nxt];
            res+=p->cnt*2;
        }
        return res;
    }
};

void solve()
{
    ll n, sum=0; cin>>n;
    string s[n+5];
    for (ll i=1; i<=n; i++) cin>>s[i], sum+=s[i].size();
    Trie trie;
    for (ll i=1; i<=n; i++) 
    {
        reverse(s[i].begin(), s[i].end());
        trie.insert(s[i]);
        reverse(s[i].begin(), s[i].end());
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) 
    {
        ans+=s[i].size()*n+sum;
        ans-=trie.count(s[i]);
    }
    cout<<ans<<endl;
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