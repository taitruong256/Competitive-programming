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
    ll a=randll(1, 1000);
    ll b=randll(1, a);
    cout<<a<<" "<<b<<endl;
}

void solution_correct(ll tc)
{
    ll n, x; cin>>n>>x;
    ll t=n;
    for (ll i=1; i<=1000000; i++) 
    {
        if (t==x)
        {
            cout<<n+i-1<<endl;
            return;
        }
        t&=(n+i);
    }
    cout<<-1<<endl;
}

void solution_check(ll tc)
{
    ll n, x; cin>>n>>x;
    if (x>n)
    {
        cout<<-1<<endl;
        return;
    }
    if (x==n)
    {
        cout<<n<<endl;
        return;
    }
    for (ll i=0; i<=63; i++) if (!(n&(1LL<<i)) && (x&(1LL<<i)))
    {
        cout<<-1<<endl;
        return;
    }

    vector<ll> bitn, bitx;
    for (ll i=0; i<=63; i++) if (n&(1LL<<i)) bitn.push_back(i);
    for (ll i=0; i<=63; i++) if (x&(1LL<<i)) bitx.push_back(i);
    reverse(bitn.begin(), bitn.end());
    reverse(bitx.begin(), bitx.end());

    if (x==0)
    {
        ll t=bitn.front()+1;
        cout<<(1LL<<t)<<endl;
        return;
    }

    ll pos=0;
    for (ll i=0; i<bitn.size(); i++) if (bitn[i]!=bitx[i]) 
    {
        pos=i;
        break;
    } 

    if (pos==0)
    {
        cout<<-1<<endl;
        return;
    }

    if (bitn[pos]==bitn[pos-1]-1)
    {
        cout<<-1<<endl;
        return;
    }

    ll ans=0;
    for (ll i=pos; i<bitn.size(); i++) ans+=(1LL<<bitn[i]); 
    ans=(1LL<<(bitn[pos]+1))-ans;    
    cout<<n+ans<<endl;
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