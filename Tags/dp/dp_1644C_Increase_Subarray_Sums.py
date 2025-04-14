for _ in range(int(input())):
    n, x=map(int, input().split(" "))
    a=[int(x) for x in input().split(" ")]
    mx=[-int(1e18)]*(n+5)
    for i in range(n):
        s=0
        for j in range(i, n):
            s+=a[j]
            mx[j-i+1]=max(mx[j-i+1], s)
    
    for i in range(n+1):
        ans=0
        for j in range(n+1): ans=max(ans, mx[j]+(min(i, j)*x))
        print(ans, end=" ")
    print()