n=int(input())
def tich(n):
    p=1
    while n>0:
       p*=(n%10)
       n//=10
    return p  

ans=max(tich(n-1), tich(n))
cnt=0
while n>0:
    n=n//10;
    cnt=cnt+1
    ans=max(ans, tich(n*10**cnt-1))
print(ans)