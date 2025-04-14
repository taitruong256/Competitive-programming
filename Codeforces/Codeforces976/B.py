import math

def solve():
    n = int(input())
    l, r = 0,  10**20 
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        if mid - int(math.sqrt(mid)) >= n:
            ans = mid
            r = mid - 1 
        else:
            l = mid + 1
    assert ans != -1
    assert ans - int(math.sqrt(ans)) == n 
    print(ans)

t = int(input())
for _ in range(t):
    solve()
