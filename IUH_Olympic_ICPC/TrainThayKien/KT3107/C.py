for _ in range(int(input())):
    m=int(input())
    n=m*(m+1)*(m+2)
    ans=0
    i=1
    while i<n:
        if ((n*n)%i==0) and (n%i!=0): ans+=1
        i+=1
    print(ans)