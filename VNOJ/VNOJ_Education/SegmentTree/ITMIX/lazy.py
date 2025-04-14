class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self.build(arr, 1, 0, self.n - 1)

    def build(self, arr, v, tl, tr):
        if tl == tr:
            self.tree[v] = arr[tl]
        else:
            tm = (tl + tr) // 2
            self.build(arr, 2 * v, tl, tm)
            self.build(arr, 2 * v + 1, tm + 1, tr)
            self.tree[v] = self.tree[2 * v] + self.tree[2 * v + 1]

    def push(self, v, tl, tr):
        if self.lazy[v] != 0:
            tm = (tl + tr) // 2
            self.tree[2 * v] += self.lazy[v] * (tm - tl + 1)
            self.tree[2 * v + 1] += self.lazy[v] * (tr - tm)
            self.lazy[2 * v] += self.lazy[v]
            self.lazy[2 * v + 1] += self.lazy[v]
            self.lazy[v] = 0

    def update(self, v, tl, tr, l, r, val, q_type):
        if l > r:
            return

        if l == tl and r == tr:
            if q_type == 1:
                self.tree[v] += val * (tr - tl + 1)
                self.lazy[v] += val
            elif q_type == 2:
                self.tree[v] *= val
                self.lazy[v] *= val
            elif q_type == 3:
                self.tree[v] = val * (tr - tl + 1)
                self.lazy[v] = val
        else:
            self.push(v, tl, tr)
            tm = (tl + tr) // 2
            self.update(2 * v, tl, tm, l, min(r, tm), val, q_type)
            self.update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val, q_type)
            self.tree[v] = self.tree[2 * v] + self.tree[2 * v + 1]

    def query(self, v, tl, tr, l, r):
        if l > r:
            return 0

        if l == tl and r == tr:
            return self.tree[v]

        self.push(v, tl, tr)
        tm = (tl + tr) // 2
        left_result = self.query(2 * v, tl, tm, l, min(r, tm))
        right_result = self.query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
        return left_result + right_result


N, M = map(int, input().split())
numbers = list(map(int, input().split()))
segment_tree = SegmentTree(numbers)

MOD = 10**9 + 7

for _ in range(M):
    query = input().split()
    q_type = int(query[0])
    L = int(query[1]) - 1
    R = int(query[2]) - 1

    if q_type == 4:
        total = segment_tree.query(1, 0, N - 1, L, R) % MOD
        print(total)
    else:
        x = int(query[3])
        segment_tree.update(1, 0, N - 1, L, R, x, q_type)
