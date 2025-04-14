def tinh(n, x, y):
    a=n*x
    b=n/2*y+n%2*x
    return min(a, b)

for _ in range(int(input())):
    n, m, x, y=map(int, input().split(" "))
    ans=0
    for i in range(n):
        s=input()
        s=s+'*'
        cnt=0
        for c in s: 
            if c=='.': cnt=cnt+1
            else: ans=ans+tinh(cnt); cnt=0
        print(ans)

            