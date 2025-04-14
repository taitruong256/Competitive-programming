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


const int N = 1e5 + 5, S = 20;

int lazy[S][4 * N];
long long t[S][4 * N];

void down(int i, int l, int r, int x) {
	int m = l + r >> 1;
	t[x][i << 1] = (m - l + 1) - t[x][i << 1];
	lazy[x][i << 1] = 1 - lazy[x][i << 1];
	t[x][i << 1 | 1] = (r - m) - t[x][i << 1 | 1];
	lazy[x][i << 1 | 1] = 1 - lazy[x][i << 1 | 1];
	lazy[x][i] = 0;
}

void upd(int i, int l, int r, int u, int v, int x) {
	if(l > v || u > r) return ;
	if(u <= l && r <= v) {
		t[x][i] = (r - l + 1) - t[x][i];
		lazy[x][i] = 1 - lazy[x][i];
		return ;
	}
	if(lazy[x][i]) down(i, l, r, x);
	int mid = l + r >> 1;
	upd(i << 1, l, mid, u, v, x);
	upd(i << 1 | 1, mid + 1, r, u, v, x);
	t[x][i] = t[x][i << 1] + t[x][i << 1 | 1];
}

long long get(int i, int l, int r, int u, int v, int x) {
	if(l > v || u > r) return 0;
	if(u <= l && r <= v) return t[x][i];
	if(lazy[x][i]) down(i, l, r, x);
	int mid = l + r >> 1;
	return get(i << 1, l, mid, u, v, x) + get(i << 1 | 1, mid + 1, r, u, v, x);
}


//--------------------------------------Viet testcase va loi giai o day-------------------------------------------
string code = "dalat17";    // nhap ma de bai tren iuhcoder vao day
void genInput(const char *cFileIn){        //ghi testcase vao file input
    freopen(cFileIn, "w", stdout);
    int n=randint(100, 1000);
    printf("%d\n", n);
    for (int i=0; i<n; i++)
    {
        int x=randint(1, 1000000);
        printf("%d ", x);
    }
    printf("\n");
    int q=randint(100, 1000);
    printf("%d\n", q);
    for (int i=0; i<q; i++)
    {
        int type=randint(1, 100)%2;
        if (type==0)
        {
            int l=randint(1, 20);
            int r=randint(n-20, n);
            if (l>r) swap(l, r);
            printf("%d %d %d\n", type+1, l, r);
        }
        else 
        {
            int l=randint(1, 20);
            int r=randint(n-20, n);
            if (l>r) swap(l, r);
            int x=randint(1, 1000000);
            printf("%d %d %d %d\n", type+1, l, r, x);
        }
    }
}
void solve(){      //loi giai cua van de
    int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		for(int j = 0; j < S; j++) if((a >> j) & 1) {
				upd(1, 1, n, i, i, j);
			}
	}
	int nq;
	scanf("%d", &nq);
	while (nq--) {
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		if(type == 1) {
			long long res = 0;
			for(int i = 0; i < S; i++) res += get(1, 1, n, l, r, i) * (1 << i);
			printf("%lld\n", res);
		} else {
			int x;
			scanf("%d", &x);
			for(int i = 0; i < S; i++) if((x >> i) & 1) {
					upd(1, 1, n, l, r, i);
				}
		}
	}
    for (int i=0; i<20; i++)
        for (int j=0; j<=4*n; j++)
            lazy[i][j]=t[i][j]=0;
}
int main(int argc, char *argv[]) {
    int Start = 1; 
    int End =12;  //tao cac test case bat dau tu Start den End
    fflush(stdin);
    srand(time(0));
    bool isGenInp = false;
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