#include <bits/stdc++.h>
using namespace std;
#define ll long long
//----------------------------------Cac ham sinh ngau nhien-------------------------------------------------------
std::mt19937 random_engine(0xdeadbeef);
template<class T>
T randint(T L, T R) { //sinh ngau nhien mot so nguyen kieu int
return L+(unsigned long long)(R-L+1)*random_engine()/(std::numeric_limits<unsigned int>::max()+1ULL);
}
typedef unsigned long long int UINT64;
UINT64 randLL(UINT64 const& min = 0, UINT64 const& max = 0) { //sinh ngau nhien mot so nguyen kieu long long int
    return (((UINT64)(unsigned int)rand() << 32) + (UINT64)(unsigned int)rand()) % (max - min) + min;
}
double randdou(double fMin, double fMax) { //sinh ngau nhien mot so nguyen kieu double
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
//sinh ngau nhien mot so
ll random(ll nmin, ll nmax){
    return rand() % (nmax - nmin + 1) + nmin;
}
int random01(){ //sinh ngau nhien mot xau nhi phan
    return rand() % 2;
}
string randstring(size_t length) { //sinh ngau nhien mot xau ki tu
    // static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";    
    static char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret; 
    if (length) {
            for (int n = 0;n < length;n++) {        
                int key = rand() % (int) (sizeof(charset1) -1);
                ret.push_back(charset1[key]);
        }
    }
    return ret;
}
char randchar(){  //sinh ngau nhien mot ki tu
    // static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";    
    static char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = rand() % (int) (sizeof(charset1) -1);
    return charset1[key];
}
void getFileName(int c, string& fileIn, string& fileOut, string code){ // tao ra ten file input va output tu dong
    string s = "";
    while(c){
        s = char(c%10+'0') + s;
        c /= 10;
    }
    fileIn = code+"."+s+".in";
    fileOut = code+"."+s+".out";
}
//-------------------------------------------------------------------------------------------------------------





//--------------------------------------Viet testcase va loi giai o day-------------------------------------------
string code = "vnoj_itmix";    // nhap ma de bai tren iuhcoder vao day
void genInput(const char *cFileIn){        //ghi testcase vao file input
    freopen(cFileIn, "w", stdout);
    int n=randint(5000, 5000);
    int q=randint(5000, 5000);
    printf("%d %d\n", n, q);
    for (int i=1; i<=n; i++)
    {
        int x=randint(1, 1000000000);
        printf("%d ", x);
    }
    for (int i=1; i<=q; i++)
    {
        int type=rand()%4+1;
        if (type==3) type-=rand()%2+1;
        printf("%d ", type);
        
        if (type==4)
        {
            int l=rand()%n+1;
            int r=rand()%n+1;
            if (l>r) swap(l, r);
            printf("%d %d\n", l, r);
        }
        else 
        {
            int l=rand()%n+1;
            int r=rand()%n+1;
            if (l>r) swap(l, r);
            int v=randint(1, 1000000000);
            printf("%d %d %d\n", l, r, v);
        }
    }
}
void solve(){      //loi giai cua van de
    ll n, q; scanf("%lld%lld", &n, &q);
    ll a[n+5];
    ll mod=1e9+7;
    for (ll i=1; i<=n; i++) scanf("%lld", &a[i]);
    while (q--)
    {
        ll type; scanf("%lld", &type);
        if (type==1)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=(a[i]+x)%mod;
        }
        else if (type==2)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=(a[i]*x)%mod;
        }
        else if (type==3)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=x;
        }
        else 
        {
            ll l, r; scanf("%lld%lld", &l, &r);
            ll ans=0;
            for (ll i=l; i<=r; i++) ans=(ans+a[i])%mod;
            printf("%lld\n", ans);
        }
    }
}
int main(int argc, char *argv[]) {
    int Start = 2; 
    int End =2;  //tao cac test case bat dau tu Start den End
    fflush(stdin);
    srand(time(0));
    bool isGenInp = true;
    //Neu isGenInp=true thi se tu dong sinh testcase dua tren ham genInput o tren dong 74
    //Neu isGenInp=false thi se nhap testcase bang tay tung testcase mot
    for(int cur = Start; cur<=End; cur++){
        random_engine.seed(0xdeadbeef^cur^End^Start^random(1, 1e9));
        string strFileIn, strFileOut;
        getFileName(cur, strFileIn, strFileOut, code);
        const char *cFileIn = strFileIn.c_str();
        const char *cFileOut = strFileOut.c_str();
        if(isGenInp) genInput(cFileIn);
        freopen(cFileIn, "r", stdin);
        freopen(cFileOut, "w", stdout);
        solve();
    }
    return 0;
}