def solve():
    n = int(input()) 
    base = 1
    res = 0
    ans = float('inf') 

    for i in range(1, 26):
        res += 1
        base *= 5
        cur = (n * base + res - 1) // res 
        
        cur = (cur + 4) // 5
        cur *= 5
        
        if cur < base:
            break
        
        res *= 5
        ans = min(ans, cur)

    print(ans)


T = int(input())
for i in range(1, T + 1):
    solve()
