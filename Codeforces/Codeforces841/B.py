t=int(input())
for i in range(t):
    n=int(input())
    ans=(n-1)*n*(n+1)//3+n*(n+1)*(2*n+1)//6
    print((ans*2022)%1000000007)