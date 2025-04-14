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

struct PalindromeTree
{
    struct node { ll len, num, link, nxt[30]; };
    vector<node> tree;
    string s;
    ll n, suff, maxn;

    PalindromeTree(){}
    PalindromeTree(string _s)
    {
        s=_s;
        tree.resize(s.size()+10);
        n=2;
        suff=2;
        tree[1]={-1, 0, 1};   //nut hu cau
        tree[2]={0, 0, 1};    //nut rong
        for (ll i=0; i<(ll)s.size(); i++) addLetter(i);
        pushNum();
    }

    bool addLetter(ll pos)
    {
        ll cur=suff, curlen=0, x=s[pos]-'a';
        //tim hau to A do dai lon nhat dang xAx bang lien ket hau to dai nhat
        cur=suff;
        while (true)
        {
            curlen=tree[cur].len;
            if (pos-1-curlen>=0 && s[pos]==s[pos-1-curlen]) break;
            cur=tree[cur].link;
        }

        if (tree[cur].nxt[x]!=0) //neu node da ton tai trong PalindromeTree thi ko can them 
        {
            tree[tree[cur].nxt[x]].num+=1;
            suff=tree[cur].nxt[x];
            return false;
        }

        suff=++n;           //them nut moi
        tree[n].len=tree[cur].len+2;
        tree[cur].nxt[x]=n;
        if (tree[n].len==1)
        {
            tree[n].link=2;
            tree[n].num+=1;
            return true;
        }
        // tim lien ket hau to dai nhat cua nut xAx la xBx
        cur=tree[cur].link;
        while (true)
        {
            curlen=tree[cur].len;
            if (pos-1-curlen>=0 && s[pos-1-curlen]==s[pos]) 
            {
                tree[n].link=tree[cur].nxt[x];
                break;
            }
            cur=tree[cur].link;
        }
        tree[n].num+=1;
        cur=n;
        return true;
    }

    void pushNum()
    {
        for (ll i=n; i>=3; i--) 
            tree[tree[i].link].num+=tree[i].num;
    }
};

void solve()
{
    string s; cin>>s;
    PalindromeTree pt(s);
    ll ans=0;
    for (ll i=3; i<=pt.n; i++) ans=max(ans, pt.tree[i].len*pt.tree[i].num);
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