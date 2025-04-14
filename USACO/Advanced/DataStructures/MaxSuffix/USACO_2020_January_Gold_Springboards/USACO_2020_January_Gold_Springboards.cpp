#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second

template<typename T, typename U> bool ckmin(T &a, const U &b){ return b < a ? a = b, true : false; }
template<typename T, typename U> bool ckmax(T &a, const U &b){ return b > a ? a = b, true : false; }

struct node{
    int tl, tr, v;
    node *l, *r;
    node(int L, int R): tl(L), tr(R), v(0), l(NULL), r(NULL) {};
    void add(){
        int tm = tl + (tr - tl)/2;
        l = new node(tl, tm);
        r = new node(tm + 1, tr);
    }
    void upd(int u, int x){
        if(tl == tr) ckmax(v, x);
        else{
            int tm = tl + (tr - tl)/2;
            if(l == NULL) add();
            if(u > tm) r->upd(u, x);
            else l->upd(u, x);
            v = max(l->v, r->v);
        }
    }
    int qry(int L, int R){
        if(tl >= L && tr <= R) return v;
        if(tl > R || tr < L) return 0;
        if(l == NULL) add();
        return max(l->qry(L, R), r->qry(L, R));
    }
};

int n, p;
vector<int> add;
//{x, y}, start or end, idx
vector<array<int, 4>> b, evt;

inline int d(const array<int, 4> &x){
    return abs(x[0] - x[2]) + abs(x[1] - x[3]);
}

int main(){
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    add.assign(p, 0);
    for(int i = 0; i < p; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        b.push_back({x1, y1, x2, y2});
        evt.push_back({x1, y1, 1, i});
        evt.push_back({x2, y2, -1, i});
    }
    // left to right, bottom to top, adding before querying
    sort(evt.begin(), evt.end(), [&](const array<int, 4> &x, const array<int, 4> &y){
        if(x[0] != y[0]) return x[0] < y[0];
        if(x[1] != y[1]) return x[1] < y[1];
        if(x[2] != y[2]) return x[2] < y[2];
        return x[3] < y[3];
    });
    node tree(0, 1e9 + 7);
    for(int i = 0; i < sz(evt); ++i){
        auto &cur = evt[i];
        if(cur[2] > 0) add[cur[3]] = tree.qry(0, cur[1]) + d(b[cur[3]]);
        else tree.upd(cur[1], add[cur[3]]);
    }
    cout << (2 * n - *max_element(add.begin(), add.end())) << "\n";
    return 0;
}