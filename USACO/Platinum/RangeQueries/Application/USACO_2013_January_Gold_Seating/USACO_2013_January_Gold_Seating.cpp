#include <bits/stdc++.h>

using namespace std;

struct Node {
    int pre , suff , mx , ind , lazy = -1;
    Node(){}
    Node (int a , int b , int c , int d) : pre(a) , suff(b) ,
    mx(c) , ind(d) {}
};

Node merge (const Node &a , const Node &b , int l , int r) {
    int mid = (l + r) / 2;
    int a_sz = mid - l + 1;
    int b_sz = r - mid;

    Node nw;
    nw.pre = a.pre == a_sz ? a_sz + b.pre : a.pre;
    nw.suff = b.suff == b_sz ? b_sz + a.suff : b.suff;

    nw.mx = a.mx;
    nw.ind = a.ind;

    if (a.suff + b.pre > nw.mx) {
        nw.mx = a.suff + b.pre;
        nw.ind = mid - a.suff + 1;
    }

    if (b.mx > nw.mx) {
        nw.mx = b.mx;
        nw.ind = b.ind;
    }

    return nw;
}

const int N = 5e5 + 5;
int n;
Node st[4 * N];

void build (int l = 0 , int r = n - 1 , int p = 1) {
    if (l == r) {
        st[p] = Node(1 , 1 , 1 , l);
        return;
    }

    int mid = (l + r) / 2;
    build(l , mid , p * 2);
    build(mid + 1 , r , p * 2 + 1);
    st[p] = merge(st[p * 2] , st[p * 2 + 1] , l , r);
}

void push_down(int l , int r , int p) {
    if (st[p].lazy != -1) {
        int nw = st[p].lazy ? 0 : (r - l + 1);
        st[p].pre = st[p].suff = st[p].mx = nw;
        if (l != r) {
            st[p * 2].lazy = st[p].lazy;
            st[p * 2 + 1].lazy = st[p].lazy;
        }
        st[p].lazy = -1;
    }
}

void update (int s , int e , bool v , int l = 0 , int r = n - 1 , int p = 1) {
    push_down(l , r , p);
    if (l > e || r < s)
        return;

    if (l >= s && r <= e) {
        int nw = v ? 0 : (r - l + 1);
        st[p].pre = st[p].suff = st[p].mx = nw;
        if (l != r) {
            st[p * 2].lazy = v;
            st[p * 2 + 1].lazy = v;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(s , e , v , l , mid , p * 2);
    update(s , e , v , mid + 1 , r , p * 2 + 1);
    st[p] = merge(st[p * 2] , st[p * 2 + 1] , l , r);
}

void find_seats (int sz , int l = 0 , int r = n - 1 , int p = 1) {
    push_down(l , r , p);
    if (l == r) {
        update(l , l , 1);
        return;
    }

    int mid = (l + r) / 2;
    if (st[p * 2].mx >= sz)
        return find_seats(sz , l , mid , p * 2);

    if (st[p * 2].suff + st[p * 2 + 1].pre >= sz) {
        int t = mid - st[p * 2].suff + 1;
        update(t , t + sz - 1 , 1);
        return;
    }

    find_seats(sz , mid + 1 , r , p * 2 + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("seating.in" , "r" , stdin);
    freopen("seating.out" , "w" , stdout);

    int m;
    cin >> n >> m;

    build();

    int ans = 0;
    while (m--) {
        char t;
        cin >> t;

        if (t == 'A') {
            int p;
            cin >> p;

            if (st[1].mx >= p) {
                find_seats(p);
            } else {
                ans++;
            }
        } else {
            int a , b;
            cin >> a >> b;
            a-- , b--;
            update(a , b , 0);
        }
    }

    cout << ans;
}