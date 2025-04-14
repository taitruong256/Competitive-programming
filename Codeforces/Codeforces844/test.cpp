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
    static char charset[]="abcdefghijklmnopqrstuvwxyz";    
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
    ifstream fout(code+"_"+to_string(tc)+"_test_output"+".txt");
    ifstream fans(code+"_"+to_string(tc)+"_user_output"+".txt");
    string s, t;
    while (fout>>s)
    {
        fans>>t;
        while (s.back()==' ') s.pop_back();
        while (t.back()==' ') t.pop_back();
        if (s!=t) 
        {
            SetConsoleTextAttribute(h, 4);
            cerr<<"Test case "<<tc<<": Wrong answer"<<endl;
            SetConsoleTextAttribute(h, 7);
            fout.close();
            fans.close();
            return;
        }
    }
    SetConsoleTextAttribute(h, 2);
    cerr<<"Test case "<<tc<<": Accept"<<endl;
    SetConsoleTextAttribute(h, 7);
    fout.close();
    fans.close();
}
void genInput(ll tc)
{
    string s=randstring(1000);
    cout<<1000<<endl;
    cout<<s<<endl;
}

void solution_correct(ll tc)
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll ans=0;
    for (ll x=0; x<=4000000; x++)
    {
        ll res=0;
        for (ll i=1; i<=n; i++)
        {
            ll k=sqrt(a[i]+x);
            if (k*k==a[i]+x) ++res;
        }
        ans=max(ans, res);
    }
    cout<<ans<<endl;
}

void solution_check(ll tc)
{
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    ll Start=1;
    ll End=100;
    code="cf";
    bool GenInputAuto=true;
    bool RunSolution=true;
    bool CheckAnswer=true;
    for (ll i=Start; i<=End; i++)
    {
        if (GenInputAuto==true) 
        {
            freopen((code+"_"+to_string(i)+"_test_input"+".txt").c_str(), "w", stdout);
            genInput(i);
        }
        if (RunSolution==true) 
        {
            freopen((code+"_"+to_string(i)+"_test_input"+".txt").c_str(), "r", stdin);
            freopen((code+"_"+to_string(i)+"_test_output"+".txt").c_str(), "w", stdout);
            solution_correct(i);
        }
        if (CheckAnswer==true) 
        {
            freopen((code+"_"+to_string(i)+"_test_input"+".txt").c_str(), "r", stdin);
            freopen((code+"_"+to_string(i)+"_user_output"+".txt").c_str(), "w", stdout);
            solution_check(i);
        }
        if (CheckAnswer==true) check(i);
    }
    cerr<<"OK";
    return 0;
}