#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <windows.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

//------------------------------------template--------------------------------------
string code;
std::mt19937 random_engine(0xdeadbeef);
int randint(int min, int max) { return rand()%(max-min+1)+min; }
ll randll(ll min, ll max) { return (((ll)rand()<<32)+(ll)rand())%(max-min+1)+min; }
double randdouble(double fMin, double fMax) { double f=(double)rand()/RAND_MAX; return fMin+f*(fMax-fMin); }
char randchar() { static char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!"; int key=rand()%26; return charset[key]; }
string randstring(ll length) 
{
    static char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";    
    string res; 
    for (int n=0; n<length; n++)
    {        
        int key=rand()%26;
        res.push_back(charset[key]);
    }
    return res;
}
vector<pair<ll, ll>> randtree(ll n)
{
    ll root=randint(1, n);
    vector<pair<ll, ll>> trees;
    ordered_set T, V;
    T.insert(root);
    for (ll i=1; i<=n; i++) if (i!=root) V.insert(i);
    for (ll i=1; i<=n-1; i++)
    {
        ll u=rand()%T.size();
        ll v=rand()%V.size();
        trees.push_back({*T.find_by_order(u), *V.find_by_order(v)});
        T.insert(*V.find_by_order(v));
        V.erase(*V.find_by_order(v));
    }
    return trees;
}
//------------------------------------end template----------------------------------

void check(ll tc)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    ifstream fout(code+"."+to_string(tc)+".out");
    ifstream fans(code+"."+to_string(tc)+".ans");
    string s, t;
    while (fout>>s)
    {
        fans>>t;
        while (s.back()==' ') s.pop_back();
        while (t.back()==' ') t.pop_back();
        if (s!=t) 
        {
            SetConsoleTextAttribute(h, 4);
            cout<<"Test case "<<tc<<": Wrong answer"<<endl;
            SetConsoleTextAttribute(h, 7);
            fout.close();
            fans.close();
            return;
        }
    }
    SetConsoleTextAttribute(h, 2);
    cout<<"Test case "<<tc<<": Accept"<<endl;
    SetConsoleTextAttribute(h, 7);
    fout.close();
    fans.close();
}

void genInput(ll tc)
{
    ofstream fin(code+"."+to_string(tc)+".inp");
    ll a=randll(1, 100000);
    ll b=randll(1, 100000);
    fin<<a<<" "<<b;
    fin.close();
}

void solve1(ll tc)
{
    ifstream fin(code+"."+to_string(tc)+".inp");
    ofstream fout(code+"."+to_string(tc)+".out");
    ll a, b; fin>>a>>b;
    if (a>b) fout<<">";
    else if (a<b) fout<<"<";
    else fout<<"=";
    fin.close();
    fout.close();
}

void solve2(ll tc)
{
    ifstream fin(code+"."+to_string(tc)+".inp");
    ofstream fout(code+"."+to_string(tc)+".ans");
    ll a, b; fin>>a>>b;
    if (a>b) fout<<">";
    else if (a<b) fout<<"<";
    else fout<<"=";
    fin.close();
    fout.close();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    ll Start=1;
    ll End=9;
    code="cf";
    bool GenInputAuto=true;
    bool CheckAnswer=true;
    for (ll i=Start; i<=End; i++)
    {
        if (GenInputAuto) genInput(i);
        solve1(i);
        if (CheckAnswer) 
        {
            solve2(i);
            check(i);
        }
    }
    return 0;
}