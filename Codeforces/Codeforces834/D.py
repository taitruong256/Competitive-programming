for _ in range(int(input())):
    n, m=map(int, input().split())
    t=n
    t2=0
    t5=0
    while (n%2==0): 
        n=n//2
        t2=t2+1
    while (n%5==0):
        n=n//5
        t5=t5+1
        
    i=60
    ans=t*m
    while (i>=1):
        x=max(0, i-t2)
        y=max(0, i-t5)   
        if (2**x*5**y<=m): 
            ans=t*(m//(2**x*5**y)*(2**x*5**y))
            break
        i=i-1
    print(ans)