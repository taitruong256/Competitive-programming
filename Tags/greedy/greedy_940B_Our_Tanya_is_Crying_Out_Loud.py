n=int(input())
k=int(input())
a=int(input())
b=int(input())

if k==1:
    print((n-1)*a)
    exit(0)
ans=0
while n>1:
    if n<k: ans+=(n-1)*a; n=1
    elif n%k==0: ans+=min(b, (n-n//k)*a); n=n//k
    elif n>k: ans+=(n%k)*a; n-=n%k
print(ans)
    