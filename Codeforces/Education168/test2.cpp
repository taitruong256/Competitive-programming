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
string code = "ctsqn16";    // nhap ma de bai tren iuhcoder vao day
void genInput(const char *cFileIn){        //ghi testcase vao file input
    freopen(cFileIn, "w", stdout);
    int n = randint(1000, 100000);
    printf("%d\n", n);
    for (int i=0; i<n; i++)
    {
        int x=randint(-1000000000, 1000000000);
        printf("%d\n", x);
    }
}
void solve(){      //loi giai cua van de
    int n; 
    scanf("%d", &n);
    int a[n+5];
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int x=-1, y=-1, d=INT_MAX;
    for (int i=1; i<=n-1; i++) if (abs(a[i+1]-a[i])<d) d=abs(a[i+1]-a[i]), x=a[i], y=a[i+1];
    printf("%d %d", x, y);
}
int main(int argc, char *argv[]) {
    int Start = 6; 
    int End = 10;  //tao cac test case bat dau tu Start den End
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