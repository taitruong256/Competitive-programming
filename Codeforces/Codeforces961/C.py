import math 

tc = int(input())

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [1.0 for _ in range(n)]
    
    
    check=True;
    for i in range(1, n):
        if a[i]<a[i-1]:
            check=False 
    if check==True:
        print(0)
        return
    
    
    ans = 0
    for i in range(1, n):
        if a[i] == 1:
            print("-1")
            return
        while b[i] + math.log2(math.log2(a[i])) < b[i - 1] + math.log2(math.log2(a[i - 1])):
            b[i] *= 2
        ans += int(math.log2(b[i]))
        
    print(ans)

for _ in range(tc):
    solve()
