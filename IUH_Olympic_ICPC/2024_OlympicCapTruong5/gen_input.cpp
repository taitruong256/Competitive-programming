#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

std::mt19937 random_engine;

template<class T>
T randint(T L, T R) {
    return L + (unsigned long long)(R - L + 1) * random_engine() / (std::numeric_limits<unsigned int>::max() + 1ULL);
}

typedef unsigned long long int UINT64;

UINT64 randLL(UINT64 const& min = 0, UINT64 const& max = 0) {
    return (((UINT64)(unsigned int)rand() << 32) + (UINT64)(unsigned int)rand()) % (max - min) + min;
}

double randdou(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

ll random(ll nmin, ll nmax) {
    return rand() % (nmax - nmin + 1) + nmin;
}

int random01() {
    return rand() % 2;
}

string randstring(size_t length) {
    static char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret;
    if (length) {
        for (int n = 0; n < length; n++) {
            int key = rand() % (int)(sizeof(charset1) - 1);
            ret.push_back(charset1[key]);
        }
    }
    return ret;
}

char randchar() {
    static char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = rand() % (int)(sizeof(charset1) - 1);
    return charset1[key];
}




void gen_input(int seed) {
    random_engine.seed(seed);
    ll l=randint(1, 100);
    ll r=l+randint(10, 100);
    cout<<l<<" "<<r;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "w", stdout);
    // #endif

    int seed = 0;   
    if (argc > 1) 
        seed = atoi(argv[1]) + time(0) % 100000; 
    else 
        seed = time(0) % 100000;
    gen_input(seed); 
    return 0;
}