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
    fileIn = s+".in";
    fileOut = s+".out";
}
//-------------------------------------------------------------------------------------------------------------


long long L=900000000, R=900000000+1000000;
vector<bool> isPrime(R - L + 1, true);
vector<ll> prime;


//--------------------------------------Viet testcase va loi giai o day-------------------------------------------
string code = "nmlt1";    // nhap ma de bai tren iuhcoder vao day
void genInput(const char *cFileIn){        //ghi testcase vao file input
    freopen(cFileIn, "w", stdout);
    ll n = 350000;
    printf("%lld\n", n);

    for (ll i=0; i<n; i++)
    {
        ll x=randint(1, (int)prime.size());
        ll y=randint(1, (int)prime.size());
        if (prime[x]==0) prime[x]+=1;
        if (prime[y]==0) prime[y]+=1;
        printf("%lld %lld\n", prime[x], prime[y]);
        // assert(1<=prime[x]+1 && prime[x]+1<=1e9);
        // assert(1<=prime[y]+1 && prime[y]+1<=1e9);
    }
}
void solve(){      //loi giai cua van de
    ll t; scanf("%lld", &t);
    cerr<<t<<endl;
    while (t--)
    {
        // ll a, b; scanf("%lld%lld", &a, &b);
        // ll x=sqrt(a*b);
        // while (x*x*x>a*b) --x;
        // bool check=false;
        // if (a*b!=x*x*x)
        // {
        //     printf("No\n");
        //     check=true;
        //     break;
        // }
        // if (check==true) continue;
        // if (a%x==0 && b%x==0) printf("Yes\n");
        // else printf("No\n");
        printf("No\n");
    }
}
int main(int argc, char *argv[]) {

      // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) {  // Xét riêng trường hợp số 1
        isPrime[1 - L] = false;
    }

    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L] && x!=0) {
            prime.push_back(x);
        }
    }

    cerr<<prime[0]<<endl;
    cerr<<prime[1]<<endl;

    int Start = 11; 
    int End =12;  //tao cac test case bat dau tu Start den End
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